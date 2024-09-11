
#include <iostream>
#include <string>
#include "Place.h"

using namespace std;

/*
Constructors
----------------------------------------------------------------------------
*/

Place::Place()
{
    
    Place_name = "Set a name";
    Node_distance = 0.0;
    Pop_density = 0.0;
    Num_houses = 0;

}

Place::Place(string _Place_name, float _Node_distance, float _Pop_density, int _Num_houses)
{
    
    Place_name = _Place_name;
    Node_distance = _Node_distance;
    Pop_density = _Pop_density;
    Num_houses = _Num_houses;

}

/*
Getters
----------------------------------------------------------------------------
*/

string Place::getPlace_name() const
{

    return this->Place_name;

}

float Place::getNode_distance() const
{

    return this->Node_distance;

}

float Place::getPop_density() const
{

    return this->Pop_density;

}

int Place::getNum_houses() const
{

    return this->Num_houses;

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

void Place::setPop_density(float _Pop_density)
{

    this->Pop_density = _Pop_density;

}

void Place::setNum_houses(int _Num_houses)
{

    this->Num_houses = _Num_houses;

}

/*
Additionals
----------------------------------------------------------------------------
*/
void Place::showInfo()
{
    cout << "Mostrar información del lugar: " << endl;
}