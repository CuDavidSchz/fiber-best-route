
#include "Menu.hpp"

// Constructor del menú
Menu::Menu() {}

// Mostrar el menú
void Menu::display() {
    std::cout << "1. Opción 1" << std::endl;
    std::cout << "2. Opción 2" << std::endl;
    std::cout << "3. Opción 3" << std::endl;
    std::cout << "Seleccione una opción: ";
}

// Procesar la entrada del usuario
void Menu::processInput(int choice) {
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

// Implementación de las opciones
void Menu::option1() {
    std::cout << "Has seleccionado la Opción 1." << std::endl;
}

void Menu::option2() {
    std::cout << "Has seleccionado la Opción 2." << std::endl;
}

void Menu::option3() {
    std::cout << "Has seleccionado la Opción 3." << std::endl;
}
