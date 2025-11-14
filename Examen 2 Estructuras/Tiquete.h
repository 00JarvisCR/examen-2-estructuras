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
	int codigo; // el codigo va ser del tamanio de la lista de tiquetes
	int distancia_total; // se calcula en el sistema
	
	float precio_base; // se calcula en el constructor
	float descuento; // se calcula en el constructor
	float precio_final; // se calcula en el constructor
	
	string nombre_usuario;
	int id_usuario;
	
	string origen;
	string destino;
	
	bool esta_utilizado;
	
public:
	int fecha[3] = {0, 0, 0}; // [0] YYY, [1] MM, [2] DD (Year/ Mouth/ Day) xd
	int hora[2] = {0, 0}; // [0] HH, [1] MM (Hora: Minuto) xd
	
	
	int get_codigo();
	int get_distancia_total();
	float get_precio_base();
	float get_descuento();
	float get_precio_final();
	
	string get_nombre_usuario();
	int get_id_usuario();
	
	string get_origen();
	string get_destino();
	
	void set_esta_utilizado(bool esta_utilizado);
	bool get_esta_utilizado();
	
	string to_string();
	
	Tiquete(int codigo, int distancia_total, char tipo, string nombre_usuario, int id_usuario, string origen, string destino); // el tiquete se crea si o si con este constructor

};

#endif

