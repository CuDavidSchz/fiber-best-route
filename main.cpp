#include <iostream>

#include "Menu.hpp"

int main() {
    Menu menu; 
    int choice;
    std::cout << "Si funciona" << std::endl;

   do {
        menu.display();
        std::cin >> choice;
        menu.processInput(choice);
    } while (choice != 0);
 


    return 0;
}  
 