#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include "ListaUsuarios.h"
#include "ListaTiquetes.h"
#include <fstream>
#include <iostream>

using namespace std;

class Archivos {
public:
	// Métodos para Usuarios
	static bool GuardarUsuarios(ListaUsuarios& listaUsuarios);
	static ListaUsuarios CargarUsuarios();
	
	// Métodos para Tiquetes
	static bool GuardarTiquetes(ListaTiquetes& listaTiquetes);
	static ListaTiquetes CargarTiquetes();
};

#endif
