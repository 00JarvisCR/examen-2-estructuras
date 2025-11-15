#include "Archivos.h"

// ==================== USUARIOS ====================

bool Archivos::GuardarUsuarios(ListaUsuarios& listaUsuarios) {
	ofstream archivo("usuarios.txt");
	
	if (!archivo.is_open()) {
		cout << "Error: No se pudo crear/abrir el archivo usuarios.txt" << endl;
		return false;
	}
	
	// Verificar si hay usuarios para guardar
	if (listaUsuarios.lista.empty()) {
		archivo << "// Archivo de usuarios (vacío)" << endl;
	}
	else {
		// Guardar cada usuario en el archivo
		for (Usuario* usuario : listaUsuarios.lista) {
			archivo << usuario->id << "," 
				<< usuario->nombre << "," 
				<< usuario->edad << "," 
				<< usuario->saldo << "," 
				<< usuario->oficio << endl;
		}
	}
	
	archivo.close();
	return true;
}

ListaUsuarios Archivos::CargarUsuarios() {
	ListaUsuarios lista;
	ifstream archivo("usuarios.txt");
	
	// Si el archivo no existe, lo creamos vacío
	if (!archivo.is_open()) {
		cout << ".";
		
		ofstream nuevoArchivo("usuarios.txt");
		if (nuevoArchivo.is_open()) {
			nuevoArchivo << "// Archivo de usuarios" << endl;
			nuevoArchivo.close();
			cout << "..";
		}
		
		return lista; // Retorna lista vacía
	}
	
	// Si el archivo existe, cargar los datos
	string linea;
	while (getline(archivo, linea)) {
		// Ignorar líneas de comentarios o vacías
		if (linea.empty() || linea.find("//") == 0) {
			continue;
		}
		
		// Buscar las comas que separan los datos
		size_t pos1 = linea.find(',');
		size_t pos2 = linea.find(',', pos1 + 1);
		size_t pos3 = linea.find(',', pos2 + 1);
		size_t pos4 = linea.find(',', pos3 + 1);
		
		if (pos1 != string::npos && pos2 != string::npos && 
			pos3 != string::npos && pos4 != string::npos) {
			
			// Extraer los datos
			int id = stoi(linea.substr(0, pos1));
			string nombre = linea.substr(pos1 + 1, pos2 - pos1 - 1);
			int edad = stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
			float saldo = stof(linea.substr(pos3 + 1, pos4 - pos3 - 1));
			int oficio = stoi(linea.substr(pos4 + 1));
			
			// Crear usuario y agregar a la lista
			Usuario* nuevoUsuario = new Usuario(id, nombre, edad, saldo, oficio);
			lista.lista.push_back(nuevoUsuario);
		}
	}
	
	archivo.close();
	cout << ".";
	return lista;
}

// ==================== TIQUETES ====================

bool Archivos::GuardarTiquetes(ListaTiquetes& listaTiquetes) {
	ofstream archivo("tiquetes.txt");
	
	if (!archivo.is_open()) {
		cout << "Error: No se pudo crear/abrir el archivo tiquetes.txt" << endl;
		return false;
	}
	
	// Verificar si hay tiquetes para guardar
	if (listaTiquetes.lista.empty()) {
		archivo << "// Archivo de tiquetes (vacío)" << endl;
	}
	else {
		// Guardar cada tiquete en el archivo
		for (Tiquete* tiquete : listaTiquetes.lista) {
			// Formatear fecha como string "YYYY/MM/DD"
			string fecha_str = to_string(tiquete->fecha[0]) + "/" + 
				to_string(tiquete->fecha[1]) + "/" + 
				to_string(tiquete->fecha[2]);
			
			// Formatear hora como string "HH:MM"
			string hora_str = to_string(tiquete->hora[0]) + ":" + 
				to_string(tiquete->hora[1]);
			
			archivo << tiquete->get_codigo() << "," 
				<< tiquete->get_distancia_total() << "," 
				<< tiquete->get_precio_base() << "," 
				<< tiquete->get_descuento() << "," 
				<< tiquete->get_precio_final() << "," 
				<< tiquete->get_nombre_usuario() << "," 
				<< tiquete->get_id_usuario() << "," 
				<< tiquete->get_origen() << "," 
				<< tiquete->get_destino() << "," 
				<< (tiquete->get_esta_utilizado() ? "1" : "0") << "," 
				<< fecha_str << "," 
				<< hora_str << endl;
		}
	}
	
	archivo.close();
	return true;
}

ListaTiquetes Archivos::CargarTiquetes() {
	ListaTiquetes lista;
	ifstream archivo("tiquetes.txt");
	
	// Si el archivo no existe, lo creamos vacío
	if (!archivo.is_open()) {
		cout << ".";
		
		ofstream nuevoArchivo("tiquetes.txt");
		if (nuevoArchivo.is_open()) {
			nuevoArchivo << "// Archivo de tiquetes" << endl;
			nuevoArchivo.close();
			cout << "..";
		}
		
		return lista; // Retorna lista vacía
	}
	
	// Si el archivo existe, cargar los datos
	string linea;
	while (getline(archivo, linea)) {
		// Ignorar líneas de comentarios o vacías
		if (linea.empty() || linea.find("//") == 0) {
			continue;
		}
		
		// Buscar todas las comas (11 campos en total)
		size_t posiciones[11];
		posiciones[0] = 0;
		
		for (int i = 1; i < 11; i++) {
			posiciones[i] = linea.find(',', posiciones[i-1] + 1);
			if (posiciones[i] == string::npos) break;
		}
		
		if (posiciones[10] != string::npos) {
			// Extraer los datos
			int codigo = stoi(linea.substr(0, posiciones[1]));
			int distancia_total = stoi(linea.substr(posiciones[1] + 1, posiciones[2] - posiciones[1] - 1));
			float precio_base = stof(linea.substr(posiciones[2] + 1, posiciones[3] - posiciones[2] - 1));
			float descuento = stof(linea.substr(posiciones[3] + 1, posiciones[4] - posiciones[3] - 1));
			float precio_final = stof(linea.substr(posiciones[4] + 1, posiciones[5] - posiciones[4] - 1));
			string nombre_usuario = linea.substr(posiciones[5] + 1, posiciones[6] - posiciones[5] - 1);
			int id_usuario = stoi(linea.substr(posiciones[6] + 1, posiciones[7] - posiciones[6] - 1));
			string origen = linea.substr(posiciones[7] + 1, posiciones[8] - posiciones[7] - 1);
			string destino = linea.substr(posiciones[8] + 1, posiciones[9] - posiciones[8] - 1);
			bool esta_utilizado = (linea.substr(posiciones[9] + 1, posiciones[10] - posiciones[9] - 1) == "1");
			
			// Extraer fecha y hora
			string fecha_str = linea.substr(posiciones[10] + 1);
			size_t hora_pos = fecha_str.find(',');
			string hora_str = fecha_str.substr(hora_pos + 1);
			fecha_str = fecha_str.substr(0, hora_pos);
			
			// Parsear fecha (YYYY/MM/DD)
			size_t f1 = fecha_str.find('/');
			size_t f2 = fecha_str.find('/', f1 + 1);
			int anio = stoi(fecha_str.substr(0, f1));
			int mes = stoi(fecha_str.substr(f1 + 1, f2 - f1 - 1));
			int dia = stoi(fecha_str.substr(f2 + 1));
			
			// Parsear hora (HH:MM)
			size_t h1 = hora_str.find(':');
			int horas = stoi(hora_str.substr(0, h1));
			int minutos = stoi(hora_str.substr(h1 + 1));
			
			// Crear tiquete (necesitamos determinar el tipo para el constructor)
			char tipo = 'x'; // Por defecto sin descuento
			if (descuento == 0.20) tipo = 'a';      // Estudiante
			else if (descuento == 0.75) tipo = 'b'; // Adulto mayor  
			else if (descuento == 0.15) tipo = 'c'; // Funcionario público
			
			Tiquete* nuevoTiquete = new Tiquete(codigo, distancia_total, tipo, nombre_usuario, id_usuario, origen, destino);
			
			// Establecer valores que no se pueden setear en el constructor
			nuevoTiquete->set_esta_utilizado(esta_utilizado);
			
			// Asignar fecha y hora cargadas
			nuevoTiquete->fecha[0] = anio;
			nuevoTiquete->fecha[1] = mes;
			nuevoTiquete->fecha[2] = dia;
			nuevoTiquete->hora[0] = horas;
			nuevoTiquete->hora[1] = minutos;
			
			lista.lista.push_back(nuevoTiquete);
		}
	}
	
	archivo.close();
	cout << ".";
	return lista;
}
