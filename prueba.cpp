#pragma once
#include <iostream>
using namespace std;
#include "Nodo.cpp"
#include<string>
#include <ctype.h>
#include<list>
#include <sstream>
#include <fstream>

class prueba{
private:
	Nodo* primero;
	list<Nodo> p1;
	list<Nodo>::iterator it;
public:	
	prueba():primero(NULL){}

	void haciendoPrueba(){
         it = p1.begin();
		 it = p1.push_back(new Nodo("Beatriz","Bruja","derecho",1));
	}
	
};