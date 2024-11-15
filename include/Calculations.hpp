
using namespace std;

#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

// Libraries
#include <vector>
#include <cmath>

// Headers
#include "Place.hpp"
#include "KDTree.hpp"



class Calculations 
{

    private:

    /*
        Auxiliary method to calculate the Nearest_Place_Distance
        ----------------------------------------------------------------------------
    */
    float calculateDistance(const Place& place1, const Place& place2);





    public:
    /*
        Calculates Nearest_Place_Distance
        ----------------------------------------------------------------------------
    */
        void calcNPD(vector<Place>& places);

    /*
        Calculates Profit_Index
        ----------------------------------------------------------------------------
    */
        void calcPI(vector<Place>& places, int alphaOption, float CPK);
   
    /*
        Sorts Places by Neares_Place_Distance
        ----------------------------------------------------------------------------
    */
        void sortPlaces(vector<Place>& places);



};
#endif