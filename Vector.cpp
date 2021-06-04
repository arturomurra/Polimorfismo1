#include "Vector.h"

using namespace std; 

Vector::Vector(){
    componentes.clear();
}

Vector::Vector(vector <Fraccion> nuevo){
    componentes = nuevo; 
}

Fraccion Vector::getComponent(int x){
    return componentes[x];
}

vector <Fraccion> Vector::getComponents(){
    return componentes; 
}

Vector Vector::operator+(Vector b){
    vector<Fraccion> componentes1 = componentes; 
    vector<Fraccion> componentes2 = b.getComponents();
    vector<Fraccion> newComponents; 
    for(int i = 0; i<max(componentes1.size(), componentes2.size()); i++){
        if(i > componentes1.size()) 
            newComponents.push_back(componentes2[i]);
        else if(i > componentes2.size())
            newComponents.push_back(componentes1[i]);
        else 
            newComponents.push_back(componentes1[i]+componentes2[i]);
    }
    Vector temp(newComponents);
    return temp; 
}

Vector Vector::operator-(Vector b){
    vector<Fraccion> componentes1 = componentes; 
    vector<Fraccion> componentes2 = b.getComponents();
    vector<Fraccion> newComponents; 
    Fraccion cero(0, 1);
    for(int i = 0; i<max(componentes1.size(), componentes2.size()); i++){
        if(i > componentes1.size()) {
            newComponents.push_back(cero - componentes2[i]);
        }
        else if(i > componentes2.size())
            newComponents.push_back(componentes1[i]);
        else {
            newComponents.push_back(componentes1[i]-componentes2[i]);
        }
    }
    Vector temp(newComponents);
    return temp; 
}

Fraccion Vector::operator*(Vector b){
    vector<Fraccion> componentes1 = componentes; 
    vector<Fraccion> componentes2 = b.getComponents();
    Fraccion res; 
    for(int i = 0; i<min(componentes1.size(), componentes2.size()); i++){
        res = res + (componentes1[i]*componentes2[i]);
    }
    return res; 
}

Fraccion Vector::productoPunt(Vector b){
    vector<Fraccion> componentes1 = componentes; 
    vector<Fraccion> componentes2 = b.getComponents();
    Fraccion res; 
    for(int i = 0; i<min(componentes1.size(), componentes2.size()); i++){
        res = res + (componentes1[i]*componentes2[i]);
    }
    return res; 
}

Vector Vector::producto(Vector b){
    vector <Fraccion> compb = b.getComponents();
    vector <Fraccion> temp; 
    if(compb.size() == componentes.size() && componentes.size() == 3){
        temp.push_back(componentes[1] * compb[2] - componentes[2]*compb[1]);
        temp.push_back(componentes[0] * compb[2] - componentes[2]*compb[0]);
        temp.push_back(componentes[0] * compb[1] - componentes[1]*compb[0]);
    }
    else {
        cout<<"Dimensiones no soportadas\n";
    }
    Vector ans(temp);
    return ans; 
}

Vector Vector::producto(int s){
    vector <Fraccion> temp; 
    for(auto i:componentes){
        i = i*s; 
        temp.push_back(i);
    }
    Vector ans(temp);
    return ans; 
}

Fraccion Vector::magnitud(){
    Fraccion ans = componentes[0].square();
    for(int i = 1; i<componentes.size(); i++){
        ans = ans + componentes[i].square();
    }
    return ans.sqroot();
}

void Vector::print(){
    for(int i = 0; i<componentes.size(); i++){
        cout<<"Componente "<<i<<": ";
        componentes[i].displayFrac();
        cout<<"\n";
    }
}

double Vector::angulo(Vector b){
    Fraccion topTerm = this->productoPunt(b);
    Fraccion bottomTerm = this->magnitud() * b.magnitud();
    Fraccion div = topTerm/bottomTerm; 
    return (acos(div.returnNumeric()) * 3.1415926535)/double(180);
}