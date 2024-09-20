#ifndef Place_h
#define Place_h

using namespace std;

// Libraries

#include <iostream>
#include <vector>

// Headers


class Place {


    protected:

    /*
        Attributes
        ----------------------------------------------------------------------------
    */
        string Place_name;
        float Node_distance;
        int Population;
        int Ppl_p_house;
        int Competitors;

        // Coordinates

        float x; 
        float y;

        // Nearest place distance
        float Near_Place_Dist;

        // Profitability Index
        float Profit_Index;


    public: 

    /*
        Constructors
        ----------------------------------------------------------------------------
    */
        Place();
        Place(string, float, int, int, int, float, float);

    /*
        Getters
        ----------------------------------------------------------------------------
    */
        string getPlace_name() const;
        float getNode_distance() const;
        int getPopulation() const;
        int getNum_houses() const;
        int getPpl_p_house() const;
        int getCompetitors() const;

        float getX() const;
        float getY() const;

        float getNear_Place_Dist() const;

        float getProfit_Index() const;

    /*
        Setters
        ----------------------------------------------------------------------------
    */
        void setPlace_name(string);
        void setNode_distance(float);
        void setPopulation(int);
        void setPpl_p_house(int);
        void setCompetitors(int);

        void setX(float);
        void setY(float);

        void setNear_Place_Dist(float);

        void setProfit_Index(float);
    /*
        Additionals
        ----------------------------------------------------------------------------
    */
        void showInfo() const;
        
};

#endif