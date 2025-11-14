#include "Usuario.h"
#include <sstream>

Usuario::Usuario() {
	this->id = 0;
	this->nombre = "";
	this->edad = 0;
	this->saldo = 0.0;
	this->oficio = 0;
}

Usuario::Usuario(int id, string nombre, int edad, float saldo, int oficio) {
	this->id = id;
	this->nombre = nombre;
	this->edad = edad; // mayor a 60 = mayor de edad
	this->saldo = saldo;
	this->oficio = oficio; // 0 = nada, 1 = estudiante, 2 = funcionario publico
}

string Usuario::to_string() {
	string of;
	if (oficio == 0) { of = "No tiene";}
	else if (oficio == 1) {of = "Estudiante";}
	else if(oficio == 2) {of = "Funcionario Pubico";}
	else {of = "No tiene oficio";}
	
	stringstream oss;
	
	oss << "ID: " << this->id << endl;
	oss << "Nombre: " << this->nombre << endl;
	oss << "Edad: " << this->edad << endl;
	oss << "Saldo: " << this->saldo << endl;
	oss << "Oficio: " << of << endl;
	
	return oss.str();
}

