#pragma once
#include <iostream>
#include "Windows.h"
using namespace std;
#include "Arbol.cpp"
#include "Nodo.cpp"
#include <fstream>
#include <string>
#include <exception>

class Interfaz{
private:
	char a;
	Arbol arb;
public:
	Interfaz(){
		this->presentacion();
		this->menu();
	}

	void menu(){
		try{
			this->arb.Leer();
			this->subMenu();
		}catch(exception &c){
			cout<<"--- NO SE PUDIERON LEER REGISTROS DESDE EL ARCHIVO ----"<<endl;
			cout<<c.what()<<endl;
		}
	}
	void subMenu(){
		do{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			cout<<endl<<endl;
			cout<<"                                       ,,,                           "<<endl;
			cout<<"                                      (o o)                          "<<endl;
			cout<<"            =-=-=-=-=-=-=-=-=-=-=-oOOo-(_)-oOOo-=-=-=-=-=-=-=-=-=-=-="<<endl;
			cout<<"           															"<<endl;
			cout<<"                Eliga la opcion que desea ver						"<<endl;
			cout<<"            	       1. Jugar             							"<<endl;
			cout<<"            	       2. Mostrar Arbol     							"<<endl;
			cout<<"            	       3. Guardar Arbol     							"<<endl;
			cout<<"            	       4. Salir											"<<endl;
			cout<<"				----->";
			cin>>a;
			switch(a){
			case '1':
				system("cls");
				this->arb.mover();
				break;
			case '2':
				system("cls");
				this->arb.imprimeArbol();
				break;
			case '3':
				system("cls");
				cout<<"Construyendo el Guardado..."<<endl;
				this->arb.guardar();
				system("pause");				
				break;
			case '4':
				exit(1);
				break;
			default:
				system("cls");				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
				cout<<endl<<endl<<"    ERROR.... "<<a<<" no es una opcion valida...                "<<endl;
				cout<<"    O se digito incorrectamente...                              "<<endl;
				system("pause");
				break;				
				system("cls");
		}
	}
		while(a!='5');
	}

	void presentacion(){
		cout<<endl<<endl<<endl;		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"		:::    :::    ::::    :::        :::     "<<endl;
		cout<<"		:+:    :+:    :+:+:   :+:      :+: :+:   "<<endl;
		cout<<"		+:+    +:+    :+:+:+  +:+     +:+   +:+  "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"		+#+    +:+    +#+ +:+ +#+    +#++:++#++: "<<endl;	
		cout<<"		+#+    +#+    +#+  +#+#+#    +#+     +#+ "<<endl;
		cout<<"		#+#    #+#    #+#   #+#+#    #+#     #+# "<<endl;
		cout<<"		 ########     ###    ####    ###     ### "<<endl;

		cout<<"		"<<endl;
		cout<<"		"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"		   +-+ +-+ +-+ +-+ +-+    "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
		cout<<"		   |A| |R| |B| |O| |L|               "<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"		   +-+ +-+ +-+ +-+ +-+ 	"<<endl;

		cout<<endl<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);	
		cout<<"	  INTEGRANTES: "<<endl<<endl;	
		cout<<"		->EDGAR RAMIREZ"<<endl;	
		cout<<"		->EDUARDO SEQUEIRA	"<<endl;
		cout<<endl<<endl<<endl;
		system("pause");
	}

	~Interfaz(){}
};