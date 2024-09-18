#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>

class Menu {
public:
    Menu(); // Constructor
    void display(); // Mostrar el menú
    void processInput(int choice); // Procesar la selección del usuario
private:
    void option1(); // Opción 1
    void option2(); // Opción 2
    void option3(); // Opción 3
};

#endif
