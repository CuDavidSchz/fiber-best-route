
using namespace std;

#ifndef MENU_HPP
#define MENU_HPP

// Libraries
#include <vector>
#include "Place.hpp"
#include "Calculations.hpp"

class Menu 
{
    public:

    /*
        Constructor
        ----------------------------------------------------------------------------
    */
        Menu(); 

    /*
        Additionals
        ----------------------------------------------------------------------------
    */
        void display();             
        void processInput(int choice); 

    private:

        vector<Place> customPlaces;  
        vector<Place> examplePlaces;
        
        /*
        OPTIONS
        ----------------------------------------------------------------------------
        */
       
       // Option 1
        void optionCreatePlaces();  
                // Option 1.1
                void optionLoadPlacesFromFile(); 
       
        // Option 2      
        void optionBestDeployment(); 

        // Option 3     
        void optionModifyCustomPlaces();  


        /*
        Additionals
        ----------------------------------------------------------------------------
        */
        void addPlace(std::vector<Place>& places);
        void displayPlaces(const std::vector<Place>& places);
        void removePlace(std::vector<Place>& places);
        void performCalculations(std::vector<Place>& places);
        void initializeExamplePlaces();

        /*
        Files
        ----------------------------------------------------------------------------
        */
        void loadPlacesFromFile(vector<Place>& places);
        void exportBestRoute(vector<Place>& places);

};

#endif 