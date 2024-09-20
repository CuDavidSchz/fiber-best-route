/* 
Nombre: David Cu Sánchez
Matrícula: A01712135

FIBER - BEST - ROUTE - TRACER

*/

using namespace std;

// Libraries

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// Headers

#include "../include/Menu.hpp"
#include "../include/Place.hpp"

#include "../include/Example.hpp" //For testing

// Main Storage

vector<Place*> place_data;


int main() {
    Menu menu; 
    int choice;
    std::cout << "Ahuevo funciona" << std::endl;

   do {
        menu.display();
        std::cin >> choice;
        menu.processInput(choice);
    } while (choice != 0);
 


    return 0;
}  
 