#ifndef LISTATIQUETES_H
#define LISTATIQUETES_H

#include "Tiquete.h"
#include <vector>

class ListaTiquetes {
public:
	vector<Tiquete*> lista;
	
	void ordenar_fecha_hora(); // ordenar la lista por fecha y por hora de los tiquetes
	
	void ordenar_monto(); // ordena la lista por monto de los tiquetes
	
	void ordenar_estacion(); // ordena la lista por estacion de los tiquetes
	
	string listar(); // lista todos los tiquetes
	
	string compradosXusuario(int id_usuario); // muestra los tiquetes por un usuario
	
	Tiquete* buscar(int codigo);
	
	
	ListaTiquetes();
private:
};

#endif

