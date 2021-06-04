#include "Fraccion.h"
#include <iostream>
#include <algorithm>


Fraccion::Fraccion()
{
    numerador = 0;
    denominador = 1;
}

void Fraccion::displayFrac(){
    cout << numerador << "/" << denominador;
}

int Fraccion::getNum(){
    return numerador;
}

int Fraccion::getDenom(){
    return denominador;
}

void Fraccion::setNum(int num){
    numerador = num; 
}

Fraccion Fraccion::multiplicar(Fraccion Fracc){
    int numFracc = Fracc.getNum();
    int denFracc = Fracc.getDenom();
    int newNum = numerador*numFracc;
    int newDen = denominador*denFracc;
    Fraccion newFracc(newNum, newDen);
    return newFracc;
}
Fraccion Fraccion::sumar(Fraccion Fracc){
    //least common denomintator
    int denFracc = Fracc.getDenom();
    int gFactor = __gcd(abs(denFracc), abs(denominador));

    int lFactor = (denFracc*denominador)/gFactor;


    int FraccNum = Fracc.getNum();
    int newNum = denFracc*numerador + denominador*FraccNum;

    Fraccion newFracc(newNum, lFactor);
    return newFracc;
}
Fraccion::Fraccion(int num, int den)
{
    int gFactor = __gcd(abs(num), abs(den));
    //cout<<num<<" "<<den<<"\n";

    numerador = num/gFactor;
    denominador = den/gFactor;

    if(denominador < 0){
        numerador *=-1;
        denominador *=-1;
    }
}

Fraccion Fraccion::operator+(Fraccion b){
    return this->sumar(b);
}

Fraccion Fraccion::operator-(Fraccion b){
    b.setNum(-1*b.getNum());
    //b.displayFrac();
    return this->sumar(b);
}

Fraccion Fraccion::operator*(Fraccion b){
    return this->multiplicar(b);
}

Fraccion Fraccion::operator*(int b){
    Fraccion temp(b, 1);
    return this->multiplicar(temp);
}

Fraccion Fraccion::operator /(Fraccion b){
    int newNum = b.getDenom();
    int newDenom = b.getNum();  
    Fraccion temp(newNum, newDenom);
    return this->multiplicar(temp);
}

Fraccion Fraccion::sqroot(){
    Fraccion temp(int(sqrt(numerador)), int(sqrt(denominador)));
    return temp; 
}

Fraccion Fraccion::square(){
    Fraccion temp(numerador*numerador, denominador*denominador);
    return temp; 
}
double Fraccion::returnNumeric(){
    return double(numerador)/double(denominador);
}

Fraccion::~Fraccion()
{
    //dtor
}
