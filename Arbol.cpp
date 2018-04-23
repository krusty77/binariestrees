#pragma once
#include <iostream>
using namespace std;
#include "Nodo.cpp"
#include<string>
#include <ctype.h>
#include<list>
#include <sstream>
#include <fstream>


class Arbol{
private:
//----------------------------Atributos-----------------------------------------
	Nodo* primero;
	string validarNombre[1];
	int numero; // se utiliza para asignarle una variable entera a cada nodo,la cual representa el nivel en el que se encuentra
	int numeroNodos; //guarda el numero de nieveles existentes en el arbol
	int repetir; // se utiliza para saber cuantas validarNombrees hay que repetir el Mostrar Arbol
	list<Nodo> p1;
	list<Nodo>::iterator it;
	string nombre;
	string especie;
//----------------------------Constructores-------------------------------------
public:
	Arbol():primero(NULL){}
	~Arbol(){}
//----------------------------Getters y Setters---------------------------------
//----------------------------Metodos-------------------------------------------
	bool estaVacio(){return primero == NULL;}//indica si el primer nodo es nulo
	void crearRaiz(){
		if(estaVacio()){//si no hay nada cree la base de la raiz
			Nodo* a2 = new Nodo("cocodrilo","reptil","I",2);//lado izquierdo tipo reptil
			Nodo* a3 = new Nodo("gallina","ave","D",2);// lado derecha gallina
			Nodo* a4 = new Nodo("cocodrilo","reptil","D",3);//el nodo cocodrilo que va a la derecha de reptil
			primero= new Nodo("0","ave","I",1);//el primero es el ave
			primero->setDer(a3);//derecha va la gallina
			primero->setIzq(a2);//izquierda va el reptil
			primero->getIzq()->setDer(a4);//y la izquierda del primero va el cocodrilo
		}
	}
	bool Ganador(Nodo* a, string op){//metodo para verificar si la opcion es ganadora
		string car,nom;
		if(a->getDer()==NULL&&op=="si"){//si no hay mas a la derecha y el Nodo es el que se penso
			cout<<"Has Ganado"<<endl;//mensaje ganador
			a=primero;//reasigna el puntero al primero para que no haiga problemas, ??? puntero con Scope de metodo
			return true;
		}else{
			return false;
		}
	}
	void BuscaPreOrden(string dato){//metodo que encapsula la busqueda en preorden
		Nodo *a1=primero;
		BpreOrden( a1,dato);
	}
	void BpreOrden( Nodo *a1,string dato){
		if (a1 != NULL){//mientra el puntero sea diferente de NULL
			if(dato==a1->getDato()->getnombre()){//si el dato es igual al nombre del puntero
				validarNombre[0]=dato;//el dato lo metemos en el vector de validacion del nombre
			}else{//si no siga buscando recursivamente
				BpreOrden( a1->getIzq(),dato);
				BpreOrden( a1->getDer(),dato);
			}
		} 
	}
	bool PerdedorIZ(Nodo* a, string op, int numero){//metodo de verificacion si es perdedor izquierda, me a pedir un puntero de verificacion
		string car,nom,nom1;
		if(a->getIzq()==NULL&&op=="no"||a->getIzq()==NULL&&op=="si"){//si la iz no es NULL y es si o no
			system("cls");
			cout<<"He Perdido"<<endl<<endl;//perdio
			cout<<"Digite la caracteristica del Nodo en el que estabas pensando"<<endl;
			cin>>car;//primero pide la caracteristica
			car=toLower(car);//hace los caracteres a miniculas
			Nodo *a1=new Nodo(a->getDato()->getespecie(),car,"I",numero);//hace el nuevo Nodo
			a->setIzq(a1);//lo setra a la izquierda xq el arbol tienda hacia la izquierda
			cout<<"Digite el nombre del Nodo en el que estabas pensando"<<endl;
			cin>>nom;
			nom=toLower(nom);
			BuscaPreOrden(nom);//busca si hay otro
			if(validarNombre[0]!=nom&&nom!=car){//si no es igual
				numero++;//aumenta el numero de nivel
				Nodo *a2=new Nodo(nom,car,"D",numero);//hace el nuevo derecha que seria el Nodo
				a=a->getIzq();//a deme su izquierda
				a->setDer(a2);//ahi le meto el nuevo anumal
				return true;
			}else{
				while(validarNombre[0]==nom||nom==car){//di ya existe el nombre o la caractetistica es = al nombre
					system("cls");
					cout<<"Se a presentado uno de los siguientes errores, por favor corrijalo,"<<endl;
					cout<<"e intentelo de nuevo"<<endl<<endl;
					cout<<"1- El nombre  ya existe en el sistema."<<endl;
					cout<<"2- El nombre es igual a la caraceristica."<<endl;
					cin>>nom;
					nom=toLower(nom);
					BuscaPreOrden(nom);
					if(validarNombre[0]!=nom&&nom!=car){
						numero++;
						Nodo *a2=new Nodo(nom,car,"D",numero);
						a=a->getIzq();
						a->setDer(a2);
						return true;//pida de nuevo los datos
					}
				}
			}
		}else{
			return false;
		}
		return false;
	}
	bool PerdedorDE(Nodo* a, string op,int numero){
		string car,nom,nom1;
		string validarNombre[2];//misma logica que la izquierda
		if(a->getDer()==NULL&&op=="no"||a->getDer()==NULL&&op=="si"){
			system("cls");
			cout<<"He Perdido"<<endl<<endl;
			cout<<"Digite la caracteristica del Nodo en el que estabas pensando"<<endl;
			cin>>car;
			car=toLower(car);
			Nodo *a1=new Nodo(a->getDato()->getespecie(),car,"I",numero);
			a->setIzq(a1);
			cout<<"Digite el nombre del Nodo en el que estabas pensando"<<endl;
			cin>>nom;
			nom=toLower(nom);
			BuscaPreOrden(nom);
			if(validarNombre[0]!=nom&&nom!=car){
				numero++;
				Nodo *a2=new Nodo(nom,car,"D",numero);
				a=a->getIzq();
				a->setDer(a2);
				return true;
			}else{
				while(validarNombre[0]==nom||nom==car){
					system("cls");
					cout<<"Se a presentado uno de los siguientes errores, por favor corrijalo,"<<endl;
					cout<<"e intentelo de nuevo"<<endl<<endl;
					cout<<"1- El nombre  ya existe en el sistema."<<endl;
					cout<<"2- El nombre es igual a la caraceristica."<<endl;
					cin>>nom;
					nom=toLower(nom);
					BuscaPreOrden(nom);
					if(validarNombre[0]!=nom&&nom!=car){
						numero++;
						Nodo *a2=new Nodo(nom,car,"D",numero);
						a=a->getIzq();
						a->setDer(a2);
						return true;
					}
				}
			}
		}else{
			return false;
		}
		return false;
	}

	void mover(){
		string dir="izq";//siempre tienda a la izq
		Nodo *a=primero;//seteamos el primero
		numero=1;//numero se empieza en 1
		MoverNodo(a,dir,numero);//metodo que encapsula el metodo del nodo
	}
	void MoverNodo(Nodo* a,string dir,int numero){
		system("cls");//empiezo a mover desde el principio
		string op;

		if(dir=="izq"){//si es izquieda
			cout<<"Digite si o no"<<endl<<endl;
			cout<<"Es: "<<a->getDato()->getespecie()<<endl;//consulta la especie
			cin>>op;//si no?
			op=toLower(op);
			if(op=="no"){//si es no
				numero++;//aumente el nivel
				if(PerdedorIZ(a,op,numero)==true){//consulte a perdedor
					a=primero;//a vuelva al primero
					return;//y devuelvase
				}else{//si no es si quiere decir que se tiene que seguir moviendo
					MoverNodo(a->getIzq(),"izq",numero);
				}
			}
			if(op=="si"){//si es si
				numero++;//aumente el nivel
				if(PerdedorDE(a,op,numero)==true){//consulta la derecha
					a=primero;
					return;
				}else{
					MoverNodo(a->getDer(),"der",numero);//si no sigase moviendo
				}
			}
		}else{//si no es izquierda es derecha
			numero++;
			cout<<"Digite si o no"<<endl<<endl;
			cout<<"Es: "<<a->getDato()->getnombre()<<endl;//consulta y aumenta el nivel
			cin>>op;
			op=toLower(op);
			if(Ganador(a,op)==true){//consulte si es ganador
				a=primero;
				system("pause");
				return;//retornese
			}else{
				if(op=="no"){//si no consulte le izquiera
					if(PerdedorIZ(a,op,numero)==true){
						a=primero;
						return;
					}else{
						MoverNodo(a->getIzq(),"izq",numero);
					}
				}
				if(op=="si"){
					MoverNodo(a->getDer(),"der",numero);
				}
			}
		}
	}
	void recorridoPreOrden(){//metodo que hace consulta de un nodo 
		Nodo *a1=primero;
		preOrden(a1); //metodo que encapsula la busqueda
		system("pause");
	} 
	void preOrden(Nodo *a1){ 
		if (a1 != NULL){//mientras no sea no null el puntero
			cout<<a1->toString()<<endl;//muestre
			preOrden( a1->getIzq());//siga recorriendo
			preOrden( a1->getDer());
		}
	} 
	string toLower(string& dato){//metodo probado con la profe para hacer que el parametro sea miniscula
		for(unsigned int i=0; i<dato.length(); i++){//recorra el vector
			dato[i] = tolower(dato[i]);//llame al metodo minicusla y asignelo campo por campo
		}
		return dato;//retornelo
	}
	int NumeroTotal(){//numero de nivel del arbol
		Nodo *a1=primero;
		int n;
		numeroNodos=0;
		n=HastaElFinal(a1);//este metodo lo encapsula
		return n;
	}
	int HastaElFinal(Nodo *a1){
		if (a1!= NULL){//mientras sea null 
			if(numeroNodos<a1->getDato()->getNumero()){//si los nodos es menor al numero del nodo
				numeroNodos=a1->getDato()->getNumero();//asignelo y veamos si hay otro que pueda entrar aqui
		 }
			HastaElFinal( a1->getIzq());//avance izq dere recursivamente
			HastaElFinal( a1->getDer());
		} 
		return numeroNodos;//retorne el final de todo la bomba el mayor de todos
	}
	void imprimeArbol(){
		system("cls");
		Nodo *a1=primero;//puntero en el primero
		int n=NumeroTotal();//deme el numero total
		repetir=1;//numerod de veces a repetir en 1
		while(repetir<=n){//mientras no sea el numero maximo del arbol
			MuestraArbol(a1,n);//muestres todo
			repetir++;
		}
		system("pause");
	}
	void MuestraArbol(Nodo *a1, int n){
		if ( a1 != NULL ){
			if(a1->getDato()->getNumero()==repetir){
				cout<<"Nivel "<<repetir<<"------------------"<<endl;//deme el numero de nivel
				cout<<a1->toString()<<endl;//imprima el Nodoito
			}
			MuestraArbol(a1->getIzq(),n);//avance recursivamente
			MuestraArbol(a1->getDer(),n);
		}
	}
	void guardar(){
		ofstream os("Nodoitos.txt", ios::out);//instanacia de archivo de lectura
		Nodo *a1=primero;//puntero en el primero
		int n=NumeroTotal();//deme el numero de nivel total
		repetir=1;//nivel 1
		while(repetir<=n){//mientras no sea el ultimo nivel
			guardarRecursivo(a1,n,os);//guarde el puntero el nivel en el archivito
			repetir++;//aumente el nivel
		}
		os.close();//cerrado para evitar problemas
	}
	void guardarRecursivo(Nodo *a1, int n,ofstream &os ){
		if (a1 != NULL){//mientras el punerto no sea NULL
			if(a1->getDato()->getNumero()==repetir){//si el numero es el mismo nivel
				os<<*a1;//escribalo
			}
			guardarRecursivo( a1->getIzq(),n,os);//avance recursivamente
			guardarRecursivo( a1->getDer(),n,os);
		}
	}
	void Leer(){
		LeerRecursivo();
		creaArbol();
	}
	void LeerRecursivo(){
		try {
			p1.clear();//hace limpieza previa
			Nodo a1; //Nodo estatica para poder hacer la lectura
			ifstream is("Nodoitos.txt", ios::in);//instancia de arvhivo de salida o lectura
			if(!is){//si el arhivo no existes 
				throw exception();//lance una excepcion
			}
		if(lecturaRecursiva(is,a1)==true){//encapsulado el cciclo para que no se encicle
			is.close();//cierro el archivo
			ErrorDeLectura();//se encarga de hacer un respaldo
		}else{
			is.close();
		}


		}catch(...){
			cout<<"Algo raro paso con la lectura..."<<endl; 
			ErrorDeLectura();//se encarga de hacer un respaldo
		}
	}
	bool lecturaRecursiva(ifstream &is, Nodo a2){
		Nodo a1 = a2;
		if(!is.eof()){//si el arvhino no esta en el final
			if(is.good()==true){//si el archivo esta bueno 
				is>>a1;//siga leyendo
				p1.push_back(a1);//metalo al final
				Nodo a2;
				lecturaRecursiva(is,a2);//avance recursivamente
			}else{
				return true;
			}
		}
		return false;
	}
	void toString(){//to strind de la lista de Nodoitos
		for(it=p1.begin(); it!= p1.end();it++)
			cout<<(*it).toString();
		cout<<"1";
		system("pause");
	}
	void creaArbol(){
		it=p1.begin();
		nombre = (*it).getDato()->getnombre();
		especie= (*it).getDato()->getespecie();
		primero = new Nodo("0","ave","I",1);
		p1.pop_front();
		//--------------------------------------
		it=p1.begin();
		nombre= (*it).getDato()->getnombre();
		especie= (*it).getDato()->getespecie();
		Nodo* a1 = new Nodo(nombre,especie,"I",2);
		primero->setIzq(a1);
		p1.pop_front();
		//--------------------------------------
		it=p1.begin();
		nombre=(*it).getDato()->getnombre();
		especie=(*it).getDato()->getespecie();
		Nodo* a3 = new Nodo("gallina","ave","D",2);
		primero->setDer(a3);
		p1.pop_front();
		buscaLista();
	}

	void buscaLista(){
		while(p1.begin()!=p1.end()){
			it=p1.begin();
			inserta_Izq_o_Der(it);
			p1.pop_front();
		}
	}
	void inserta_Izq_o_Der(list<Nodo>::iterator it){//iterador por parametro
        Nodo *a1=primero;//puntero viendo a primero
		it=p1.begin();//iterador en primero
		if((*it).getDato()->getLado()=="I"){//si el lado es izquierda
		   insertaIzquierda(a1,it);//inserte a la izquierda
	   }
		if((*it).getDato()->getLado()=="D"){//si es la derecha inserte a la derecha
		   insertaDerecha(a1,it);
	   }
	}
	void insertaIzquierda(Nodo *a1,list<Nodo>::iterator it){
		string nom,especie,lado;
		int num;
		if ( a1 != NULL ){ //si el puntero no es null
			if((*it).getDato()->getnombre()==a1->getDato()->getespecie()//si el nombre del iterador es igual a la especie del puntero
				&&a1->getDato()->getNumero()!=1&&a1->getIzq()==NULL//y el numero del nivel del puntero  es diferente a 1 y su izquier es = a NULL
				&&(*it).getDato()->getNumero()-1==a1->getDato()->getNumero()){//y el numero del iterador anterior es = al numero del puntero
					nom=(*it).getDato()->getnombre();//asigne el nombre del iterador 
					especie=(*it).getDato()->getespecie();// y de la especie
					lado=(*it).getDato()->getLado();//su lado
					num=(*it).getDato()->getNumero();//y su numero
				Nodo *a2=new Nodo(nom,especie,lado,num);//hago un nuevo Nodo con lo del iterador
				a1->setIzq(a2);//y los seteo a la izquierda
			}
			insertaIzquierda( a1->getIzq(),it);//siga insertando recursivamente
			insertaIzquierda( a1->getDer(),it);
		}
	}
	void insertaDerecha(Nodo *a1,list<Nodo>::iterator it){//misma logid que es de la izquieda
		string nom,especie,lado;
		int num;
		if ( a1 != NULL ){ 
			if((*it).getDato()->getespecie()==a1->getDato()->getespecie()&&a1->getDato()->getLado()=="I"&&a1->getDer()==NULL&&(*it).getDato()->getNumero()-1==a1->getDato()->getNumero()){//getDer()==NULL
				nom=(*it).getDato()->getnombre();
				especie=(*it).getDato()->getespecie();
				lado=(*it).getDato()->getLado();
				num=(*it).getDato()->getNumero();
				Nodo *a2=new Nodo(nom,especie,lado,num);
				a1->setDer(a2);
			}
			insertaDerecha( a1->getIzq(),it);
			insertaDerecha( a1->getDer(),it);
		}
	}
	void ErrorDeLectura(){// si al querer abrir el archivo este no exite, este metodo se encarga de volverlo a crear
		crearRaiz();
		guardar();
		LeerRecursivo();
	}
};








		


