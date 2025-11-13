#include "Nodo.h"

Nodo::Nodo(string nombre) {
	this->nombre = nombre;
	
	this->distancia_sig = 0;
	this->distancia_sec = 0;
	this->distancia_ant = 0;
	
	this->sig = nullptr;
	this->sec = nullptr;
	
	this->ant = nullptr;
}

Nodo::~Nodo() {}

