#include "ListaUsuarios.h"

ListaUsuarios::ListaUsuarios() {
	this-> lista = {};
}

Usuario* ListaUsuarios::buscarXid(int id) {
	for(Usuario* usuario: this->lista){
		if(usuario && usuario->id == id){ // usuario al principio para verificar que no sea null el usuario
			return usuario;
		}
	}
	return nullptr;
}

