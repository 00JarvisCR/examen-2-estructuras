#ifndef TIQUETE_H
#define TIQUETE_H

#include <iostream>

using namespace std;

class Tiquete {
	// ============= Descuentos =============
	// estudiante --------------> 'a' = 20%
	// adulto mayor ------------> 'b' = 75%
	// funcionario publico -----> 'c' = 15%
	
private:
	int codigo;
	int distancia_total;
	float precio_base;
	
	float descuento;
	float precio_final; // aplicando IVA y descuentos
	
public:
	int fecha[2]; // [0] YYY, [1] MM, [2] DD (Year/ Mouth/ Day) xd
	int hora[1]; // [0] HH, [1] MM (Hora: Minuto) xd
	
	int get_codigo();
	int get_distancia_total();
	float get_precio_base();
	float get_descuento();
	
	string to_string();
	
	
	Tiquete(int codigo, int distancia_total, char tipo);

};

#endif

