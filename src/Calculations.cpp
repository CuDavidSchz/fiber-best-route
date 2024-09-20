
using namespace std;

// Libraries

#include <iostream>
#include <algorithm>  
#include <cmath> 

// Headers
#include "../include/Calculations.hpp" 



/*
    * Method: calculateDistance
    * Description: Calculate the Euclidean distance between two places.
    * Formula: sqrt((X1 - X2)^2 + (Y1 - Y2)^2)
    
    * ---------------------------------------------------------------------------
 */
float Calculations::calculateDistance(const Place& place1, const Place& place2) 
{
    return sqrt(pow(place1.getX() - place2.getX(), 2) + pow(place1.getY() - place2.getY(), 2));
}

/*
    * Method: calcNPD
    * Description: Calculate the closest distance between each place and any other place in the list.
    * Updates the Near_Place_Dist attribute of each place.
    
    * ---------------------------------------------------------------------------
*/
void Calculations::calcNPD(vector<Place>& places) 
{
    for (size_t i = 0; i < places.size(); i++) 
    {
        float minDistance = numeric_limits<float>::max();  // Initial value
        
        for (size_t j = 0; j < places.size(); j++) 
        {
            if (i != j) // Prevents calculating distance with itself
            {  
                float distance = calculateDistance(places[i], places[j]);
                if (distance < minDistance) 
                {
                    minDistance = distance;
                }
            }
        }
        places[i].setNear_Place_Dist(minDistance);
    }
}

/*
    * Method: calcPI
    * Description: Calculates the Profitability Index (PI) for all 
    * locations in the list based on the selected alpha option and cost per 
    * kilometer (CPK).
    
    * ---------------------------------------------------------------------------
*/
void Calculations::calcPI(vector<Place>& places, int alphaOption, float CPK) {

    // Constants
    float alpha;
    const float beta = 0.1f;  // Constant to avoid zero division

    // Set alpha based on user selection
    if (alphaOption == 1) 
    {
        alpha = 0.7f;
    } 
    else 
    {
        alpha = 0.3f;
    }

    for (auto& place : places)
    {
        // Varaible bank
        int NH = place.getNum_houses(); 
        float NPD = place.getNear_Place_Dist();
        int C = place.getCompetitors(); 

        // PI formula
        float PI = (1.0f / (1 + C)) * (NH * (1 + alpha * (1 / (NPD + beta)))) / CPK;

        // Set PI value to the place
        place.setProfit_Index(PI);
    }
}

/*
    * Method: sortPlaces
    * Description: Sorts the vector of places based on three criteria:
    * - Profitability Index (PI)
    * - Node Distance 
    * - Near Place Distance (NPD)
    
    * Places are sorted in descending order of PI, then by ascending Node Distance, and finally
    * by ascending NPD for ties.
    
    * ---------------------------------------------------------------------------
*/
void Calculations::sortPlaces(vector<Place>& places) 
{
    // Sorting places based on three criteria
    sort(places.begin(), places.end(), [](const Place& a, const Place& b) 
    {
        if (a.getProfit_Index() != b.getProfit_Index()) 
        {
            // Sort by PI in descending order (higher PI first)
            return a.getProfit_Index() > b.getProfit_Index();
        } 
        else if (a.getNode_distance() != b.getNode_distance()) 
        {
            // If PI is the same, sort by Node Distance in ascending order (closer first)
            return a.getNode_distance() < b.getNode_distance();
        } 
        else 
        {
            // If both PI and Node Distance are the same, sort by NPD in ascending order (closer first)
            return a.getNear_Place_Dist() < b.getNear_Place_Dist();
        }
    });

    // Display the list
    for (const auto& place : places) 
    {
        cout << place.getPlace_name() << " - PI: " << place.getProfit_Index()
             << ", Node Distance: " << place.getNode_distance()
             << ", NPD: " << place.getNear_Place_Dist() << " km" << endl;
    }
}