#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

class Arbol {
public:
	Nodo* Alajuela = nullptr;
	Nodo* Rio_Segundo = nullptr;
	
	Nodo* Heredia = nullptr;
	Nodo* San_Jose = nullptr;
	Nodo* Curridabat = nullptr;
	Nodo* Cartago = nullptr;
	
	Nodo* San_Ramon = nullptr;
	Nodo* Palmares = nullptr;
	Nodo* Naranjo = nullptr;
	Nodo* Grecia = nullptr;
	
	string ver_nodos();
	
	Arbol();
	~Arbol();
private:
};

#endif

