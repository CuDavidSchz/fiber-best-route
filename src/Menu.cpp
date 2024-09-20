
using namespace std;

// Libraries

// Headers

#include "../include/Menu.hpp"

/*
    Constructor
    ---------------------------------------------------------------------
*/

Menu::Menu() {}

/*
    Show Menu
    ---------------------------------------------------------------------
*/

void Menu::display() 
{
    std::cout << "1. Opción 1" << std::endl;
    std::cout << "2. Opción 2" << std::endl;
    std::cout << "3. Opción 3" << std::endl;
    std::cout << "Seleccione una opción: ";
}
/*
    Process the user selection
    ---------------------------------------------------------------------
*/

void Menu::processInput(int choice) 
{
    switch(choice) {
        case 1:
            option1();
            break;
        case 2:
            option2();
            break;
        case 3:
            option3();
            break;
        default:
            std::cout << "Opción inválida" << std::endl;
    }
}

/*
    O P T I O N S 
    ---------------------------------------------------------------------
*/


/*
    Option 1
    ---------------------------------------------------------------------
*/

void Menu::option1() 
{
    std::cout << "Has seleccionado la Opción 1." << std::endl;
}

/*
    Option 2
    ---------------------------------------------------------------------
*/
void Menu::option2() 
{
    std::cout << "Has seleccionado la Opción 2." << std::endl;
}

/*
    Option 3
    ---------------------------------------------------------------------
*/
void Menu::option3() 
{
    std::cout << "Has seleccionado la Opción 3." << std::endl;
}
