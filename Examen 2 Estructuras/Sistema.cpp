#include "Sistema.h"

Sistema::Sistema() {
	//	this->arbol = Arbol();
	this->tiquetes = Archivos::CargarTiquetes(); // aqui se deberia implementar archivos para cargar (tiquetes.txt)
	this->usuarios = Archivos::CargarUsuarios(); // aqui se deberia implementar archivos para cargar (usuario.txt)
}

int Sistema::buscar_ruta(Nodo* actual, Nodo* destino, Nodo* anterior, int distancia_acumulada) {
	if (actual == nullptr) {
		return -1; // No se encontró ruta
	}
	
	if (actual == destino) {
		return distancia_acumulada; // Llegamos al destino
	}
	
	// Probamos todas las direcciones posibles excepto volver por donde vinimos
	int resultado = -1;
	
	// Siguiente principal
	if (actual->sig != nullptr && actual->sig != anterior) {
		resultado = buscar_ruta(actual->sig, destino, actual, 
								distancia_acumulada + actual->distancia_sig);
		if (resultado != -1) return resultado;
	}
	
	// Siguiente secundario
	if (actual->sec != nullptr && actual->sec != anterior) {
		resultado = buscar_ruta(actual->sec, destino, actual, 
								distancia_acumulada + actual->distancia_sec);
		if (resultado != -1) return resultado;
	}
	
	// Anterior
	if (actual->ant != nullptr && actual->ant != anterior) {
		resultado = buscar_ruta(actual->ant, destino, actual, 
								distancia_acumulada + actual->distancia_ant);
		if (resultado != -1) return resultado;
	}
	
	return -1; // No se encontró ruta desde este nodo
}

int Sistema::calcular_distancia(Nodo* origen, Nodo* destino) {
	if (origen == nullptr || destino == nullptr || origen == destino) {
		return 0;
	}
	
	// Para otras rutas, usa el método recursivo
	return buscar_ruta(origen, destino, nullptr, 0);
}

char Sistema::calcular_tipo_descuento(Usuario* usuario) {
	if (usuario->edad >= 60){
		return 'b'; // descuento adulto mayor
	}
	if (usuario->oficio == 0) {
		return 'x'; // no hay descuento
	}
	if (usuario->oficio == 1) {
		return 'a'; // descuento estudiante
	}
	if (usuario->oficio == 2) {
		return 'c'; // descuento funcionario publico
	}
	
	return 'x'; // no hay descuento (no deberia caer aqui)
}

void Sistema::Registrarse() {
	crear_usuario();
	Archivos::GuardarUsuarios(usuarios);
}

void Sistema::loguearse() {
	int id = Utilidades::in_int("Ingresa tu ID: ");
	
	Usuario* usuario = usuarios.buscarXid(id);
	
	if (!usuario) {
		cout << "\nEste usuario no existe." << endl;
		return;
	}
	else{
		cout << "\nLogueado correctamente" << endl;
	}
	
	do{
		Utilidades::pausar();
		Utilidades::limpiar();
		
		cout << "=========== MENU ===========" << endl;
		cout << "1. Comprar tiquetes" << endl;
		cout << "2. Abordar con tiquete" << endl;
		cout << "3. Ver Tiquetes" << endl;
		cout << "4. Recargar Saldo" << endl;
		cout << "5. Salir\n" << endl;
		
		int opc = Utilidades::in_int("Ingresa la opcion deseada: ", 1, 5);
		if (opc == 1) { Utilidades::limpiar(); comprarTiquete(usuario); }
		else if (opc == 2) { Utilidades::limpiar(); abordarTren(usuario); }
		else if (opc == 3) { Utilidades::limpiar(); verTiquetes(usuario); }
		else if (opc == 4) { Utilidades::limpiar(); recargarSaldo(usuario); }
		else if (opc == 5) { return; }
		else{
			cout << "\nIngrese una opcion valida" << endl;
		}
	} while(true);
	
}

void Sistema::comprarTiquete(Usuario* usuario){
	crear_tiquete(usuario);
	Archivos::GuardarTiquetes(tiquetes);
}

void Sistema::abordarTren(Usuario* usuario){
	int codigo_tiquete;
	
	cout << "=========== ABORDAJE ===========" << endl;
	codigo_tiquete = Utilidades::in_int("Ingrese el Codigo del tiquete a abordar: ");
	Tiquete* tiquete = this->tiquetes.buscar(codigo_tiquete);
	
	if (tiquete){
		if (usuario->id == tiquete->get_id_usuario() and !tiquete->get_esta_utilizado()){
			tiquete->set_esta_utilizado(true);
			cout << "\nBus abordado correctamente" << endl;
			cout << "\n====== TIQUETE USADO ======" << endl;
			cout << tiquete->to_string();
		}
		else if(usuario->id == tiquete->get_id_usuario() and tiquete->get_esta_utilizado()){
			cout << "\nEste tiquete ya ha sido utilizado" << endl;
		}
		else { 
			cout << "\nEste tiquete no es tuyo" << endl;
		}
	}
	else{
		cout << "\nNo se encontro este tiquete" << endl;
	}
	Archivos::GuardarTiquetes(tiquetes);
}

void Sistema::verTiquetes(Usuario* usuario) {
	do{
		cout << "=========== Vista De Tiquetes ===========" << endl;
		cout << "1. Ver mis tiquetes" << endl;
		cout << "2. Ver tiquetes ordenados por fecha/hora" << endl;
		cout << "3. Ver tiquetes ordenados por monto" << endl;
		cout << "4. Ver tiquetes ordenados por estacion" << endl;
		cout << "5. Salir\n " << endl;
		
		int opc;
		do {
			opc = Utilidades::in_int("Ingrese una opcion correspondiente: ", 1, 5);
			
			if (opc == 1) { ver_compradosXusuario(usuario->id); break; }
			else if (opc == 2) { ver_ordenadorXfecha_hora(); break;}
			else if (opc == 3) { ver_ordenadoXmonto(); break; }
			else if (opc == 4) { ver_ordenadoXestacion(); break; }
			else if (opc == 5) { return; }
			else { cout << "\nIngrese una opcion valida\n"; }
			
		} while(true);
		Utilidades::pausar();
		Utilidades::limpiar();
	} while(true);
	
}

void Sistema::crear_tiquete(Usuario* usuario){
	int codigo = tiquetes.lista.size() + 1;
	char tipo = calcular_tipo_descuento(usuario);
	string nombre_usuario = usuario->nombre;
	int id_usuario = usuario->id;
	
	Nodo* origen_nodo = new Nodo("");
	Nodo* destino_nodo = new Nodo("");
	
	
	int opcion;
	bool bucle = true;
	cout << "========== UBICACIONES ==========" << endl;
	cout << this->arbol.ver_nodos();
	cout << "\nCual es tu lugar de origen?\n";
	do {
		opcion = Utilidades::in_int("Ingrese numero correspondiente: ", 1, 10);
		
		switch(opcion) {
		case 1:
			origen_nodo = this->arbol.Alajuela;
			bucle = false;
			break;
			
		case 2:
			origen_nodo = this->arbol.Rio_Segundo;
			bucle = false;
			break;
			
		case 3:
			origen_nodo = this->arbol.Heredia;
			bucle = false;
			break;
			
		case 4:
			origen_nodo = this->arbol.San_Jose;
			bucle = false;
			break;
			
		case 5:
			origen_nodo = this->arbol.Curridabat;
			bucle = false;
			break;
			
		case 6:
			origen_nodo = this->arbol.Cartago;
			bucle = false;
			break;
			
		case 7:
			origen_nodo = this->arbol.San_Ramon;
			bucle = false;
			break;
			
		case 8:
			origen_nodo = this->arbol.Palmares;
			bucle = false;
			break;
			
		case 9:
			origen_nodo = this->arbol.Naranjo;
			bucle = false;
			break;
			
		case 10:
			origen_nodo = arbol.Grecia;
			bucle = false;
			break;
			
		default:
			cout << "\nIngrese un opcion correcta" << endl;
			break;
		}
	} while(bucle);
	
	Utilidades::limpiar();
	
	cout << "========== UBICACIONES ==========" << endl;
	cout << this->arbol.ver_nodos();
	cout << "\nCual es tu lugar de destino?\n";
	
	bucle = true;
	
	do {
		opcion = Utilidades::in_int("Ingrese numero correspondiente: ", 1, 10);
		
		switch(opcion) {
		case 1:
			destino_nodo = this->arbol.Alajuela;
			bucle = false;
			break;
			
		case 2:
			destino_nodo = this->arbol.Rio_Segundo;
			bucle = false;
			break;
			
		case 3:
			destino_nodo = this->arbol.Heredia;
			bucle = false;
			break;
			
		case 4:
			destino_nodo = this->arbol.San_Jose;
			bucle = false;
			break;
			
		case 5:
			destino_nodo = this->arbol.Curridabat;
			bucle = false;
			break;
			
		case 6:
			destino_nodo = this->arbol.Cartago;
			bucle = false;
			break;
			
		case 7:
			destino_nodo = this->arbol.San_Ramon;
			bucle = false;
			break;
			
		case 8:
			destino_nodo = this->arbol.Palmares;
			bucle = false;
			break;
			
		case 9:
			destino_nodo = this->arbol.Naranjo;
			bucle = false;
			break;
			
		case 10:
			destino_nodo = arbol.Grecia;
			bucle = false;
			break;
			
		default:
			cout << "\nIngrese un opcion correcta" << endl;
			break;
		}
	} while(bucle);
	
	int distancia = calcular_distancia(origen_nodo, destino_nodo);
	
	Tiquete* tiquete =  new Tiquete(codigo, distancia, tipo, nombre_usuario, id_usuario, origen_nodo->nombre, destino_nodo->nombre);
	
	if(usuario->saldo < tiquete->get_precio_final()) {
		cout << "\nSaldo insuficiente, por favor recargue el saldo primero antes de comprar\n" << endl;
		cout << "Saldo actual: " << usuario->saldo << endl;
		cout << "Costo del pasaje: " << tiquete->get_precio_final() << endl;
	}
	else {
		cout << "\nTiquete comprado con exito\n\n";
		cout << "Saldo antes: " << usuario->saldo << endl;
		
		usuario->saldo -= tiquete->get_precio_final();
		tiquetes.lista.push_back(tiquete);
		
		cout << "Costo del pasaje: " << tiquete->get_precio_final() << endl;
		cout << "Saldo actual: " << usuario->saldo << endl;
	}
	
}




void Sistema::recargarSaldo(Usuario* usuario) {
	cout << "=================== Recargas ===================" << endl;
	float saldo = Utilidades::in_float("Ingrese el saldo que quiera ingresar a su cuenta: ", 0 , 999999999999999999);
	
	usuario->saldo += saldo;
	
	cout << "\nSaldo agregado correctamente" << endl;
	Archivos::GuardarUsuarios(usuarios);
}

void Sistema::crear_usuario(){
	cout << "=================== Registro ===================" << endl;
	int id;
	
	do{
		id = Utilidades::in_int("Ingrese su id: ");
		
		Usuario* existe = usuarios.buscarXid(id);
		
		
		if(!existe){
			break;
		}
		else {
			cout << "Este id ya existe, escoja uno distinto" << endl;
		}
	} while(true);

	
	string nombre = Utilidades::in_string("Ingrese su nombre: ");
	int edad = Utilidades::in_int("Ingrese su edad: ", 5, 122);
	
	cout << "Seleccione su oficio: " << endl;
	cout << "1. Ninguno" << endl;
	cout << "2. Estudiante" << endl;
	cout << "3. Funcionario publico\n" << endl;
	
	int oficio = Utilidades::in_int("Ingrese su opcion: ", 1, 3) - 1;
	
	Usuario* usuario = new Usuario(id, nombre, edad, 0, oficio);
	
	usuarios.lista.push_back(usuario);
	
	cout << "\nUsuario registrado con exito" << endl;

}

void Sistema::ver_compradosXusuario(int id_usuario){
	cout << tiquetes.compradosXusuario(id_usuario);
}

void Sistema::ver_ordenadorXfecha_hora() {
	tiquetes.ordenar_fecha_hora(); // ordena la lista por fecha y hora
	cout << tiquetes.listar(); //muestra toda la lista
}

void Sistema::ver_ordenadoXmonto() {
	tiquetes.ordenar_monto(); // ordena por monto
	cout << tiquetes.listar(); // muestra toda la lista
}

void Sistema::ver_ordenadoXestacion() {
	tiquetes.ordenar_estacion();
	cout << tiquetes.listar();
}



