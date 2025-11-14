#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include "Usuario.h"
#include <vector>

class ListaUsuarios {
public:
	vector<Usuario*> lista;
	
	Usuario* buscarXid(int id); // busca al usuario por el id
	
	ListaUsuarios();
private:
};

#endif

