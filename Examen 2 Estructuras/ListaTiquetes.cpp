#include "ListaTiquetes.h"

ListaTiquetes::ListaTiquetes() {
	this->lista = {};
}


void ListaTiquetes::ordenar_fecha_hora(){
	// implementar
	// ordena la lista por fecha y hora
}

void ListaTiquetes::ordenar_monto() {
	// implementar
	// ordena la lista por monto
}

void ListaTiquetes::ordenar_estacion() {
	// implementar
	// ordena la lista por estacion
}

string ListaTiquetes::listar(){
	//implementar
	string lista = "lista completa ordenada. (implementar en ListaTiquetes)\n";
	
	return lista;
}

string ListaTiquetes::compradosXusuario(int id_usuario) {
	// implementar
	string lista = "lista de este usuario (implementar en ListaTiquetes)\n";
	
	return lista;
}

Tiquete* ListaTiquetes::buscar(int codigo) {
	for(Tiquete* tiquete: this->lista){
		if(tiquete && tiquete->get_codigo() == codigo){ // usuario al principio para verificar que no sea null el usuario
			return tiquete;
		}
	}
	return nullptr;
}
