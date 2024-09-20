#ifndef Menu_hpp
#define Menu_hpp


// Libraries

#include <iostream>

// Headers

class Menu {
    
    public:

    /*
        Constructor
        ----------------------------------------------------------------------------
    */
        Menu();

    /*
        Show Menu
        ----------------------------------------------------------------------------
    */
        void display();

    /*
        Process the user selection
        ----------------------------------------------------------------------------
    */
        void processInput(int choice); 


    private:

    /*
        Option 1
        ----------------------------------------------------------------------------
    */
        void option1();

    /*
        Option 2
        ----------------------------------------------------------------------------
    */
        void option2();

    /*
        Option 3
        ----------------------------------------------------------------------------
    */
        void option3();
};

#endif