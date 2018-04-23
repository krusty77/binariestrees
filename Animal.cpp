#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include<fstream>

class Animal{
public:	
	string nombre;
	string especie;
	int numero; // numero de nivel
	string lado; // con este string sabemos si es Nodo derecho o izquierdo
public:
	Animal(string nombre, string especie,string lado ,int numero=0){
		this->nombre = nombre;
		this->especie = especie;
		this->lado = lado;
		this->numero = numero;
	}
	string getnombre(){return this->nombre;}
	int getNumero(){return this->numero;}
	string getespecie(){return this->especie;}void setnombre(string nombre){this->nombre = nombre;}
	void setespecie(string especie){this->especie = especie;}
	void setNumero(int numero){this->numero=numero;}
	void setLado(string lado){this->lado=lado;}
	string getLado(){return this->lado;}
	string toString(){ 
		stringstream ss;
		ss<<"-----------------"<<endl;
		ss << "Nombre: " << nombre << endl;
		ss << "Especie: " << especie << endl;
		ss<<  "Numero: " <<numero<<endl;
		ss<<  "Lado: " <<lado<<endl;
		ss<<"-----------------"<<endl;
		return ss.str();
	}

};