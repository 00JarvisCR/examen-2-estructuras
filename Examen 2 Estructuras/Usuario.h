#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

class Usuario {
public:
	int id;
	string nombre;
	int edad; // mayor a 60 = mayor de edad
	float saldo;
	int oficio; // 0 = nada, 1 = estudiante, 2 = funcionario publico
	
	string to_string();
	
	Usuario();
	Usuario(int id, string nombre, int edad, float saldo, int oficio);
private:
};

#endif

