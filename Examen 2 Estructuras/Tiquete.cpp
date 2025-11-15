#include "Tiquete.h"
#include <sstream>
#include <chrono>
#include <ctime>

Tiquete::Tiquete(int codigo, int distacia_total, char tipo, string nombre_usuario, int id_usuario, string origen, string destino) {
	this->codigo = codigo; // el codigo va se del tamanio de la lista de tiquetes
	this->distancia_total = distacia_total; // se calcula en el sistema
	this->nombre_usuario = nombre_usuario;
	this->id_usuario = id_usuario;
	this->origen = origen;
	this->destino = destino;
	this->esta_utilizado = false; // nunca va empezar utilizado

	this->precio_base = 75.0 * float(distacia_total); // 50 por kilometro
	
	if (tipo ==  'a') {this->descuento = 0.20;} // descuento tipo estudiante
	else if (tipo == 'b') {this->descuento = 0.75;} // descuento tipo adulto mayor
	else if (tipo == 'c') {this->descuento = 0.15;} // descuento tipo funcionario publico
	else {this->descuento = 0.0;} // no descuento
	
	float precio_descuento = this->precio_base - (this->precio_base * this->descuento); // obtener descuento
	this->precio_final = precio_descuento + (precio_descuento * 0.13); // obtener precion final
	
	// ========== ASIGNAR FECHA Y HORA ACTUAL ==========
	auto ahora = chrono::system_clock::now();
	time_t tiempo_actual = chrono::system_clock::to_time_t(ahora);
	tm* tiempo_local = localtime(&tiempo_actual);
	
	// Asignar fecha: [0] Año, [1] Mes, [2] Día
	this->fecha[0] = tiempo_local->tm_year + 1900;  // Año completo
	this->fecha[1] = tiempo_local->tm_mon + 1;      // Mes (1-12)
	this->fecha[2] = tiempo_local->tm_mday;         // Día del mes
	
	// Asignar hora: [0] Horas, [1] Minutos
	this->hora[0] = tiempo_local->tm_hour;          // Horas (0-23)
	this->hora[1] = tiempo_local->tm_min;           // Minutos (0-59)
}

int Tiquete::get_codigo() {return this->codigo;}

int Tiquete::get_distancia_total() {return this->distancia_total;}

float Tiquete::get_precio_base() {return this->precio_base;}

float Tiquete::get_descuento() {return this->descuento;}

float Tiquete::get_precio_final() {return this->precio_final;}

string Tiquete::get_nombre_usuario() {return this->nombre_usuario;}

int Tiquete::get_id_usuario() { return this->id_usuario; } 

string Tiquete::get_origen() {return this->origen;}

string Tiquete::get_destino() {return this->destino;}

void Tiquete::set_esta_utilizado(bool esta_utilizado) {this->esta_utilizado = esta_utilizado;}

bool Tiquete::get_esta_utilizado() {return this->esta_utilizado;}


string Tiquete::to_string() {
	string estado;
	
	if(esta_utilizado){
		estado = "Utilizado";
	}
	else{
		estado = "Disponible";
	}
	
	stringstream oss;
	
	oss << "Codigo:             " << this->codigo << endl;
	oss << "Usuario:            " << this->nombre_usuario << endl;
	oss << "ID Usuario:         " << this->id_usuario << endl;
	oss << "Distancia de viaje: " << this->distancia_total << " Km"<< endl;
	oss << "Punto Origen:       " << this->origen << endl;
	oss << "Punto Destino:      " << this->destino << endl;
	oss << "Fecha de compra:    " << fecha[0] << "/" << fecha[1] << "/" << fecha[2] << endl;
	oss << "Hora de compra:     " << hora[0] << ":" << hora[1] << endl;
	oss << "Precio base:        " << this->precio_base << " CRC" << endl;
	oss << "Descuento:          " << this->descuento * 100 << "%" << endl;
	oss << "IVA:                13%\n";
	oss << "Precio final:       " << this->precio_final << " CRC" << endl;
	oss << "Estado:             " << estado << endl;
	
	return oss.str();
}


