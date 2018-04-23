#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Animal.cpp"
#include <sstream>
#include<fstream>

class Nodo{
//----------------------------Atributos-----------------------------------------
public:
	Nodo* der; //puntero derecha
	Nodo* izq; //puntero izquierda
	Animal* ani;
//----------------------------Constructores-------------------------------------
public:
	Nodo(){		
		ani = new Animal("","","",0);
	}
	Nodo(string nombre, string especie,string lado ,int numero=0):izq(NULL),der(NULL){//por defecto
		ani = new Animal(nombre,especie,lado,numero);
	}
	~Nodo(){}
//----------------------------Getters y Setters---------------------------------
	void setDer(Nodo *der){this->der = der;}
	void setIzq(Nodo *izq){this->izq = izq;}	
    Nodo* getDer(){return this->der;}
	Nodo* getIzq(){return this->izq;}
	Animal* getDato(){return this->ani;}
//----------------------------Metodos-------------------------------------------
	
	string toString(){
		return ani->toString();
	}
	
	friend ostream& operator <<(ostream & os, Nodo & c){
		return os<<c.getDato()->nombre<<endl<<c.getDato()->especie<<endl<<c.getDato()->lado<<endl<<c.getDato()->numero<<endl;
	}
	friend istream& operator >>(istream& is , Nodo& c){
		return is>>c.getDato()->nombre>>c.getDato()->especie>>c.getDato()->lado>>c.getDato()->numero;
	}
};