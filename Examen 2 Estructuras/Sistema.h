#ifndef SISTEMA_H
#define SISTEMA_H

#include "Nodo.h"
#include "ListaTiquetes.h"
#include "ListaUsuarios.h"
#include "Arbol.h"
#include "Utilidades.h"

class Sistema {
public:
	// ====================================================== Funciones Utiles =========================================================
	
	int calcular_distancia(Nodo* origen, Nodo* destino); // retorna la distancia total entre el punto de origen y el punto de destino
	char calcular_tipo_descuento(Usuario* usario); // devuelve 'a', 'b', 'c' dependiendo de la edad o el oficio del usuario
	
	
	//==================================================================================================================================
	
	
	//======================================================= Funciones Menu ===========================================================
	
	void Registrarse(); // registrar un usuario;
	void loguearse(); // se loguea pidiendo datos y buscando al usario y entra a un sub-menu
	
	// sub-menu despues de loguearse
	void recargarSaldo(Usuario* usuario); // le suma el saldo al usario por si ocupa mas
	void comprarTiquete(Usuario* usuario); // compra un tiquete
	void abordarTren(Usuario* usario); // selecciona que tiquete quiere usar y deja de estar disponible (simula la entrada al tren)
	void verTiquetes(Usuario* usuario); // entra a un sub-menu donde le salen las opciones de como quiere ver los tiquetes
	
	
	//==================================================================================================================================
	
	void crear_usuario(); // pide datos y crea un usuario, ademas lo inserta en la ListaUsuarios
	
	void crear_tiquete(Usuario* usuario); // pidee datos para que crear un tiquete, ademas lo inserta en la ListaTiquetes ( usar funciones utiles )
	
	void ver_compradosXusuario(int id_usuario); // para ver los tiquetes comprados por el usuario
	
	void ver_ordenadorXfecha_hora(); // para poder ver los tiquetes ordenado por fecha y hora

	void ver_ordenadoXmonto(); // para poder ver los tiquetes ordenados por monto
	
	void ver_ordenadoXestacion(); // para poder ver lo tiquetes ordenados por estaciones
	
	
	
	Sistema();
private:
	Arbol arbol;
	ListaTiquetes tiquetes;
	ListaUsuarios usuarios;
	
	int buscar_ruta(Nodo* actual, Nodo* destino, Nodo* anterior, int distancia_acumulada); // MOVER A PRIVATE
};

#endif

