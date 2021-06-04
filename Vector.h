#include <iostream>
#include <vector>
#include "Fraccion.h"

using namespace std; 

class Vector{
    private: 
        vector<Fraccion> componentes; 
    public: 
        Vector();
        Vector(vector <Fraccion>);
        Vector operator +(Vector);
        Vector operator -(Vector);
        Fraccion operator *(Vector); //producto punto
        Vector producto(Vector); //producto cruz
        Fraccion magnitud(); // pythagoras
        Fraccion productoPunt(Vector); 
        Vector producto(int); // escalar
        double angulo(Vector);
        void print();
        Fraccion getComponent(int);
        vector <Fraccion> getComponents();
};