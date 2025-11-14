#include "ListaTiquetes.h"

ListaTiquetes::ListaTiquetes() {
	this->lista = {};
}


void ListaTiquetes::ordenar_fecha_hora(){
	// implementar
}

void ListaTiquetes::ordenar_monto() {
	// implementar
}

void ListaTiquetes::ordenar_estacion() {
	// implementar
}

string ListaTiquetes::listar(){
	//implementar
	string lista = "lista completa";
	
	return lista;
}

string ListaTiquetes::compradosXusuario(int id_usuario) {
	// implementar
	string lista = "lista de este usuario";
		
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
