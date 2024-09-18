

#ifndef Place_h
#define Place_h

#include <iostream>
#include <vector>

using namespace std;

class Place {

    protected:
        string Place_name;
        float Node_distance;
        float Pop_density;
        int Num_houses;

    public: 

        // Constructors
        Place();
        Place(string, float, float, int);

        // Getters
        string getPlace_name() const;
        float getNode_distance() const;
        float getPop_density() const;
        int getNum_houses() const;

        // Setters
        void setPlace_name(string);
        void setNode_distance(float);
        void setPop_density(float);
        void setNum_houses(int);

        // Additionals
        void showInfo();
        
};

#endif