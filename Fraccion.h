#ifndef FRACCION_H
#define FRACCION_H
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Fraccion
{
    protected:
        int numerador;
        int denominador;

    public:
        Fraccion();
        Fraccion(int, int);
        virtual ~Fraccion();
        void displayFrac();
        int getNum();
        int getDenom();
        void setNum(int);
        Fraccion multiplicar(Fraccion);
        Fraccion sumar(Fraccion);  
        Fraccion operator +(Fraccion);
        Fraccion operator -(Fraccion);
        Fraccion operator *(Fraccion);
        Fraccion operator *(int);
        Fraccion operator /(Fraccion);
        Fraccion sqroot();
        Fraccion square();
        double returnNumeric();
};

#endif // FRACCION_H