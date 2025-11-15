#include<iostream>

#include "Sistema.h"

using namespace std;

int main () {
	Sistema sis;
	
	do{
		
		cout << "\n============= Menu Principal =============" << endl;
		cout << "1. Registrarse" << endl;
		cout << "2. Loguearse" << endl;
		cout << "3. Salir\n" << endl;
		
		int opc;
		
		opc = Utilidades::in_int("Ingrese una opcion: ", 1, 3);
		
		if(opc == 1) { Utilidades::limpiar(); sis.Registrarse(); }
		if(opc == 2) { sis.loguearse(); }
		if(opc == 3) { break; }
		
		Utilidades::pausar();
		Utilidades::limpiar();
	} while(true);
	return 0;
}

