/* 
Nombre: David Cu Sánchez
Matrícula: A01712135

FIBER - BEST - ROUTE - TRACER

*/

// Libraries
#include <iostream>

// Headers
#include "../include/Menu.hpp"

using namespace std;

int main() 
{
    Menu menu;
    int choice;
    bool exit = false;

    while (!exit) 
    {
        menu.display();
        while (!(cin >> choice)) 
        {
            cout << "Entrada inválida. Por favor, ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == 4) 
        {
            exit = true;
        }

        menu.processInput(choice);
    }

    return 0;
};