
using namespace std;

// Libraries
#include <iostream>
#include <string>

// Headers
#include "../include/Place.hpp"



/*
Constructors
----------------------------------------------------------------------------
*/

// Default constructor

Place::Place() 

    : Place_name("Set a name"),
      Node_distance(0.0f),
      Population(0),
      Ppl_p_house(1),
      Competitors(0),
      x(0.0f),
      y(0.0f),
      Near_Place_Dist(0.0f),
      Profit_Index (0.0f)

{}

// Parameterized constructor

Place::Place(string _Place_name, float _Node_distance, int _Population, 
    int _Ppl_p_house, int _Competitors, float _x, float _y)
    : Place_name(_Place_name),
      Node_distance(_Node_distance),
      Competitors(_Competitors),
      x(_x),
      y(_y),
      Near_Place_Dist(0.0f),
      Profit_Index(0.0f)
    

{
    // Population Validation
    if (_Population >= 0)
        Population = _Population;
    else {
        Population = 0;
        cerr << "Error: La población no puede ser negativa. Se establece en 0 por defecto." << endl;
    }
    
    // Ppl_p_house Validation
    if (_Ppl_p_house >= 1)
        Ppl_p_house = _Ppl_p_house;
    else {
        Ppl_p_house = 1; 
        cerr << "Error: Las personas por casa no pueden ser cero o negativas. Se establece en 1 por defecto." << endl;
    }
}
/*
Getters
----------------------------------------------------------------------------
*/

string Place::getPlace_name() const
{

    return this -> Place_name;

}

float Place::getNode_distance() const
{

    return this -> Node_distance;

}

int Place::getPopulation() const
{

    return this -> Population;

}

int Place::getPpl_p_house() const
{

    return this -> Ppl_p_house;

}

int Place::getNum_houses() const
{
    return Population / Ppl_p_house;
}

float Place::getX() const
{
    
    return this -> x;

}

float Place::getY() const
{

    return this -> y;

}

float Place::getNear_Place_Dist() const
{

    return this -> Near_Place_Dist;

}

float Place::getProfit_Index() const
{

    return this -> Profit_Index;

}
/*
Setters
----------------------------------------------------------------------------
*/

void Place::setPlace_name(string _Place_name)
{

    this->Place_name = _Place_name;

}

void Place::setNode_distance(float _Node_distance)
{

    this->Node_distance = _Node_distance;

}

void Place::setPopulation(int _Population)
{
    // Extra validation
    if (_Population >= 0)
    {
        this->Population = _Population;
    }
    else 
    {
        this->Population = 0;
        cerr << "Error: La población no puede ser negativa. Se establece en 0 por defecto." << endl;
    }
}

void Place::setPpl_p_house(int _Ppl_p_house)
{
    // Extra validation
    if (_Ppl_p_house >= 1)
    {
        this->Ppl_p_house = _Ppl_p_house;
    }
    else 
    {
        this->Ppl_p_house = 1; 
        cerr << "Error: Las personas por casa no pueden ser cero. Se establece en 1 por defecto." << endl;
    }
}

void Place::setX(float _x)
{

    this -> x = _x;

}

void Place::setY(float _y)
{

    this -> y = _y;

}

void Place::setNear_Place_Dist(float _Near_Place_Dist)
{

    this -> Near_Place_Dist = _Near_Place_Dist;

}

void Place::setProfit_Index(float _Profit_Index)
{
    // Extra validation
    if (_Profit_Index >= 0) 
    {
        this->Profit_Index = _Profit_Index;
    } 
    else 
    {
        cerr << "Error: El índice de rentabilidad no puede ser negativo. Se establece en 0 por defecto." << endl;
        this->Profit_Index = 0;
    }
}

/*
Additionals
----------------------------------------------------------------------------
*/
void Place::showInfo()
{
    cout << "Información del lugar:" << endl;
    cout << "Nombre: " << Place_name << endl;
    cout << "Distancia al nodo: " << Node_distance << " km" << endl;
    cout << "Población: " << Population << endl;
    cout << "Personas por casa: " << Ppl_p_house << endl;
    cout << "Número de casas: " << getNum_houses() << endl;
    cout << "Competidores: " << Competitors << endl;
    cout << "Coordenadas: (" << x << ", " << y << ")" << endl;
    cout << "Distancia al lugar más cercano: " << Near_Place_Dist << " km" << endl;
    cout << "Índice de Rentabilidad (PI): " << Profit_Index << endl; 
}