
using namespace std;

// Libraries
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>


// Headers
#include "../include/Menu.hpp"
#include "../include/KDTree.hpp"


/*
    Constructor
    ---------------------------------------------------------------------
*/
Menu::Menu() 
{
    initializeExamplePlaces();
}

/*
    Shows menu options
    ---------------------------------------------------------------------
*/
void Menu::display() 
{
    cout << "=========================" << endl;
    cout << "        M E N Ú          " << endl;
    cout << "=========================" << endl;
    cout << "1. Crear una lista de lugares" << endl;
    cout << "2. Crear mejor ruta de despliegue" << endl;
    cout << "3. Modificar la lista personalizada" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opción: ";
}

/*
    Process user's input
    ---------------------------------------------------------------------
*/
void Menu::processInput(int choice) 
{
    switch(choice)
    {
        case 1:
            optionCreatePlaces();
            break;
        case 2:
            optionBestDeployment();
            break;
        case 3:
            optionModifyCustomPlaces();
            break;
        case 4:
            cout << "Gracias por usar el programa. ¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
    }
}

/*
    Option 1 : Create a custom place vector
    ---------------------------------------------------------------------
*/
void Menu::optionCreatePlaces() 
{
        int Option_1_choice; 
        char continueAdding;

        cout << endl;
        cout << "=== Crear una lista de lugares ===" << endl;
        cout << endl;
        cout << "1. Crear desde cero" << endl; 
        cout << "2. Cargar lugares desde un archivo" << endl;
        cout << "3. Regresar al menu" << endl;
        cout << "Selecciona una opción: ";


        cin >> Option_1_choice; 

    switch(Option_1_choice)
    {
        case 1: 
            // Add places manually
            continueAdding = 's';
            while (continueAdding == 's' || continueAdding == 'S') 
            {
                addPlace(customPlaces);
                cout << "¿Desea agregar otro lugar? (s/n): ";
                cin >> continueAdding;
            }
            break;

        case 2:
            // Load places from file
            optionLoadPlacesFromFile();
            break;

        case 3:
            cout << endl;
            cout << "== Regresando al menú principal ==" << endl;
            cout << endl;
            break;

        default:
            cout << endl;
            cout << "Opción inválida. Por favor, intente de nuevo." << endl;
            cout << endl;
            optionCreatePlaces();
    }
}
/*
    Option 2 : Find the best route
    ---------------------------------------------------------------------
*/
void Menu::optionBestDeployment() 
{
    cout << "=== Crear mejor ruta de despliegue ===" << endl;

    // Preguntar al usuario qué lista desea usar
    cout << "Seleccione la lista de lugares a utilizar:" << endl;
    cout << "1. Lista personalizada" << endl;
    cout << "2. Lista de ejemplo" << endl;
    cout << "Seleccione una opción: ";

    int listChoice;
    cin >> listChoice;

    vector<Place> selectedPlaces; //A copy to preserve the original data
    if (listChoice == 1) 
    {
        if (customPlaces.empty()) 
        {
            cout << "La lista personalizada está vacía. Por favor, cree una lista primero." << endl;
            return;
        }
        selectedPlaces = customPlaces;
    } 
    else if (listChoice == 2) 
    {
        selectedPlaces = examplePlaces;
    } 
    else 
    {
        cout << "Opción inválida. Regresando al menú principal." << endl;
        return;
    }

    // Ask for a custom CPK
    float CPK;
    cout << "¿Desea proporcionar un Costo por Kilómetro (CPK) personalizado? (s/n): ";
    
    char cpkChoice;
    cin >> cpkChoice;

    if (cpkChoice == 's' || cpkChoice == 'S') 
    {
        cout << "Ingrese el Costo por Kilómetro (CPK): ";
        while (!(cin >> CPK) || CPK <= 0) 
        {
            cout << "Entrada inválida. Ingrese un número positivo para el CPK: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } 
    else 
    {
        // Use a default CPK
        CPK = 500.0f; 
        cout << "Usando CPK predeterminado: " << CPK << endl;
    }

    // Perform the calculations
    performCalculations(selectedPlaces);

    // Ask for another iteration using other alpha
    char continueAlpha = 's';
    while (continueAlpha == 's' || continueAlpha == 'S') 
    {
    
        int alphaOption;
        cout << "Seleccione el valor de alpha:" << endl;
        cout << "1. Alpha = 0.7" << endl;
        cout << "2. Alpha = 0.3" << endl;
        cout << "Seleccione una opción: ";

        while (!(cin >> alphaOption) || (alphaOption != 1 && alphaOption != 2)) 
        {
            cout << "Entrada inválida. Seleccione 1 o 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Create a copy of the vector to work
        vector<Place> placesCopy = selectedPlaces;

        // Create Calculations object
        Calculations calculations;

        // Calculate PI
        calculations.calcPI(placesCopy, alphaOption, CPK);

        // Sort Places
        calculations.sortPlaces(placesCopy);

        // Show Results
        cout << "=== Resultados de la ruta de despliegue ===" << endl;
        displayPlaces(placesCopy);

        // Ask for another iteration with another alpha
        cout << "¿Desea probar con otro valor de alpha? (s/n): ";
        cin >> continueAlpha;

        // Save files
        char saveChoice;
        cout << "¿Desea guardar los resultados en un archivo? (s/n): ";
        cin >> saveChoice;

        if (saveChoice == 's' || saveChoice == 'S') 
        {
            exportBestRoute(placesCopy);
            cout << "Los resultados se han guardado en 'Ruta.txt'." << endl;
        }
    }


}

/*
    Option 3 : Modify the custom vector
    ---------------------------------------------------------------------
*/
void Menu::optionModifyCustomPlaces() 
{
    if (customPlaces.empty()) 
    {
        cout << "La lista personalizada está vacía. Por favor, cree una lista primero." << endl;
        return;
    }

    bool continueModifying = true;

    while (continueModifying) 
    {
        cout << "=== Modificar la lista personalizada ===" << endl;
        cout << "1. Agregar un lugar" << endl;
        cout << "2. Eliminar un lugar" << endl;
        cout << "3. Mostrar lista de lugares" << endl;
        cout << "4. Regresar al menú principal" << endl;
        cout << "Seleccione una opción: ";
        int modifyChoice;
        cin >> modifyChoice;

        switch(modifyChoice) 
        {
            case 1:
                addPlace(customPlaces);
                break;
            case 2:
                removePlace(customPlaces);
                break;
            case 3:
                displayPlaces(customPlaces);
                break;
            case 4:
                continueModifying = false;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }
    }
}

/*
    Option 4 : Load places from a file
    ---------------------------------------------------------------------
*/
void Menu::optionLoadPlacesFromFile()
{
    cout << endl;
    cout << "=== Cargar lugares desde un archivo ===" << endl;
    cout << endl;
    loadPlacesFromFile(customPlaces);
}

/*
    AUXILIARY METHODS
    ---------------------------------------------------------------------
*/

/*
    Load Files
    ---------------------------------------------------------------------
*/

void Menu::loadPlacesFromFile(vector<Place>& places)
{
    string filename;
    cout << "Ingrese el nombre del archivo (con extensión): ";
    cin >> filename;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ifstream inputFile(filename.c_str());

    if (!inputFile)
    {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        // Return to menu
        return; 
    }

    places.clear();

    string line;
    while (getline(inputFile, line))
    {
        // Bank of variables
        string name;
        float nodeDistance;
        int population;
        int pplPerHouse;
        int competitors;
        float x, y;

        istringstream ss(line);

        // Read data
        if (getline(ss, name, ',') &&
            ss >> nodeDistance && ss.get() &&
            ss >> population && ss.get() &&
            ss >> pplPerHouse && ss.get() &&
            ss >> competitors && ss.get() &&
            ss >> x && ss.get() &&
            ss >> y)
        {
            // Create and add the place
            Place newPlace(name, nodeDistance, population, pplPerHouse, competitors, x, y);
            places.push_back(newPlace);
        }
        else
        {
            cerr << "Error al leer la línea: " << line << endl;
        }
    }

    inputFile.close();
    cout << "Lugares cargados exitosamente desde " << filename << endl;
    return;
}

/*
    Export Files
    ---------------------------------------------------------------------
*/
void Menu::exportBestRoute(vector<Place>& places)
{
    ofstream fileBestRoute("Ruta.txt", ios::out);

    if (fileBestRoute.fail())
    {
        cout << "No se pudo abrir el archivo para guardar la ruta." << endl;
        return;
    }

    fileBestRoute << "=== Resultados de la ruta de despliegue ===" << endl;

    for (const auto& place : places)
    {
        fileBestRoute << place.getPlace_name() 
                    << " - PI: " << place.getProfit_Index()
                    << ", Node Distance: " << place.getNode_distance()
                    << ", NPD: " << place.getNear_Place_Dist() 
                    << " km" << endl;
    }

    fileBestRoute.close();
    cout << "Los resultados se han guardado correctamente." << endl;
}

/*
    Add another place
    ---------------------------------------------------------------------
*/
void Menu::addPlace(vector<Place>& places) 
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clean

    // Variable bank
    string name;
    float nodeDistance;
    int population;
    int pplPerHouse;
    int competitors;
    float x, y;

    cout << "Ingrese el nombre del lugar: ";
    getline(cin, name);

    cout << "Ingrese la distancia al nodo (km): ";
    while (!(cin >> nodeDistance) || nodeDistance < 0) 
    {
        cout << "Entrada inválida. Ingrese un número no negativo para la distancia al nodo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese la población: ";
    while (!(cin >> population) || population < 0) 
    {
        cout << "Entrada inválida. Ingrese un número no negativo para la población: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el número de personas por casa: ";
    while (!(cin >> pplPerHouse) || pplPerHouse <= 0) 
    {
        cout << "Entrada inválida. Ingrese un número positivo para personas por casa: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese el número de competidores: ";
    while (!(cin >> competitors) || competitors < 0) 
    {
        cout << "Entrada inválida. Ingrese un número no negativo para competidores: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese la coordenada X: ";
    while (!(cin >> x)) 
    {
        cout << "Entrada inválida. Ingrese un número para la coordenada X: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Ingrese la coordenada Y: ";
    while (!(cin >> y)) 
    {
        cout << "Entrada inválida. Ingrese un número para la coordenada Y: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Create and add the place
    Place newPlace(name, nodeDistance, population, pplPerHouse, competitors, x, y);
    places.push_back(newPlace);
    cout << "Lugar agregado exitosamente." << endl;
}

/*
    Show the places
    ---------------------------------------------------------------------
*/
void Menu::displayPlaces(const vector<Place>& places) 
{
    if (places.empty()) 
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    for (const auto& place : places) 
    {
        place.showInfo();
        cout << "-----------------------" << endl;
    }
}

/*
    Delete a place
    ---------------------------------------------------------------------
*/
void Menu::removePlace(vector<Place>& places) 
{
    if (places.empty()) 
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    displayPlaces(places);

    cout << "Ingrese el índice del lugar que desea eliminar (comenzando desde 1): ";
    int index;
    while (!(cin >> index) || index < 1 || index > places.size()) 
    {
        cout << "Entrada inválida. Ingrese un número entre 1 y " << places.size() << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Delete the place
    places.erase(places.begin() + (index - 1));
    cout << "Lugar eliminado exitosamente." << endl;
}

/*
    CALCULATIONS
    ---------------------------------------------------------------------
*/
void Menu::performCalculations(vector<Place>& places) 
{
    Calculations calculations;

    calculations.calcNPD(places);
}

/*
    EXAMPLE LIST
    ---------------------------------------------------------------------
*/
void Menu::initializeExamplePlaces() 
{
    examplePlaces.push_back(Place("Ciudad A", 10.0f, 5000, 4, 2, 100.0f, 200.0f));
    examplePlaces.push_back(Place("Ciudad B", 15.0f, 3000, 5, 1, 150.0f, 250.0f));
    examplePlaces.push_back(Place("Ciudad C", 20.0f, 8000, 3, 0, 200.0f, 300.0f));
    examplePlaces.push_back(Place("Ciudad D", 8.0f, 2500, 4, 1, 120.0f, 210.0f));
    examplePlaces.push_back(Place("Ciudad E", 12.0f, 4000, 4, 2, 130.0f, 220.0f));
    examplePlaces.push_back(Place("Ciudad F", 5.0f, 1500, 5, 3, 140.0f, 230.0f));
    examplePlaces.push_back(Place("Ciudad G", 18.0f, 6000, 3, 1, 160.0f, 260.0f));
    examplePlaces.push_back(Place("Ciudad H", 25.0f, 9000, 4, 0, 170.0f, 270.0f));
    examplePlaces.push_back(Place("Ciudad I", 30.0f, 10000, 3, 2, 180.0f, 280.0f));
    examplePlaces.push_back(Place("Ciudad J", 6.0f, 2000, 4, 1, 190.0f, 290.0f));
}
