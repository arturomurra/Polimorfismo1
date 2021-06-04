#include <bits/stdc++.h>
#include "Vector.cpp"
#include "Fraccion.cpp"

using namespace std; 

int main(){
    srand(1);
    cout<<"Hello World!"<<endl;
    vector <Fraccion> temp1, temp2;  
    for(int i = 0; i<4; i++){
        Fraccion temp(rand()%10+1, rand()%10+1);
        temp1.push_back(temp);
    } 
    for(int i = 0; i<4; i++){
        Fraccion temp(rand()%10+1, rand()%10+1);
        temp2.push_back(temp);
    } 


    Vector a(temp1); 
    Vector b(temp2);

    a.print();
    b.print(); 
    cout<<"Suma\n";
    (a+b).print();
    cout<<"Resta\n";
    (a-b).print();
    cout<<"Producto punto\n";
    (a*b).displayFrac();
    cout<<"\nProducto Cruz\n";
    a.producto(b);
    cout<<"\nAngulo interno\n";
    cout<<a.angulo(b);
    cout<<"\nEscalamiento\n";
    a.producto(3).print();
    
    return 0;
}