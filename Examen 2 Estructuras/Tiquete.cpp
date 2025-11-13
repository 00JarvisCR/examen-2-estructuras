#include "Tiquete.h"

Tiquete::Tiquete(int codigo, int distacia_total, char tipo) {
	this->codigo = codigo;
	this->distancia_total = distacia_total;
	
	this->precio_base = 50.0 * float(distacia_total); 
	
	if (tipo ==  'a') {this->descuento = 0.20;} // descuento tipo estudiante
	
	else if (tipo == 'b') {this->descuento = 0.75;} // descuento tipo adulto mayor
	
	else if (tipo == 'c') {this->descuento = 0.15;} // descuento tipo funcionario publico
	
	else {this->descuento = 0.0;} // no descuento
	
	float precio_descuento = this->precio_base - (this->precio_base * this->descuento); // obtener descuento
	this->precio_final = precio_descuento + (precio_descuento * 0.13); // obtener precion final
}

