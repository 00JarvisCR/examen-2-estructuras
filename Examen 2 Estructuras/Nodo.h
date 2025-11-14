#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo {

public:
	string nombre; //nombre de el lugar (Alajuela - San Ramon - Grecia - ...)
	
	Nodo* sig; // siguiente (izquierda)
	Nodo* sec; // siguiente secundario (derecha)
	Nodo* ant; // anterior (padre)
	
	int distancia_sig; // distancia del siguiente
	int distancia_sec; // distancia del siguiente secundario
	int distancia_ant; // distancia del anterior
	
	Nodo(string nombre);
	~Nodo();

private:
};

#endif

