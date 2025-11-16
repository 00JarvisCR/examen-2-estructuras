#include "ListaTiquetes.h"
#include <algorithm>
#include <sstream>

ListaTiquetes::ListaTiquetes() {
	this->lista = {};
}


void ListaTiquetes::ordenar_fecha_hora() {
	std::sort(lista.begin(), lista.end(),
			  [](Tiquete* a, Tiquete* b) {
				  
				  if (a == nullptr && b == nullptr) return false;
				  if (a == nullptr) return false;
				  if (b == nullptr) return true;
				  
				  // Comparar año
				  if (a->fecha[0] != b->fecha[0])
					  return a->fecha[0] < b->fecha[0];
				  
				  // Comparar mes
				  if (a->fecha[1] != b->fecha[1])
					  return a->fecha[1] < b->fecha[1];
				  
				  // Comparar dia
				  if (a->fecha[2] != b->fecha[2])
					  return a->fecha[2] < b->fecha[2];
				  
				  // Comparar hora
				  if (a->hora[0] != b->hora[0])
					  return a->hora[0] < b->hora[0];
				  
				  // Comparar minuto
				  return a->hora[1] < b->hora[1];
			  });
}

void ListaTiquetes::ordenar_monto() {
	std::sort(lista.begin(), lista.end(),
			  [](Tiquete* a, Tiquete* b) {
				  if (a == nullptr && b == nullptr) return false;
				  if (a == nullptr) return false;
				  if (b == nullptr) return true;
				  
				  // Ascendente por precio 
				  return a->get_precio_final() < b->get_precio_final();
			  });
}

void ListaTiquetes::ordenar_estacion() {
	std::sort(lista.begin(), lista.end(),
			  [](Tiquete* a, Tiquete* b) {
				  if (a == nullptr && b == nullptr) return false;
				  if (a == nullptr) return false;
				  if (b == nullptr) return true;
				  
				  // Primero por origen (alfabetico)
				  if (a->get_origen() != b->get_origen())
					  return a->get_origen() < b->get_origen();
				  
				  // Si tienen mismo origen, por destino
				  if (a->get_destino() != b->get_destino())
					  return a->get_destino() < b->get_destino();
				  
				  // Si mismo origen/destino, por fecha/hora 
				  if (a->fecha[0] != b->fecha[0])
					  return a->fecha[0] < b->fecha[0];
				  
				  if (a->fecha[1] != b->fecha[1])
					  return a->fecha[1] < b->fecha[1];
				  
				  if (a->fecha[2] != b->fecha[2])
					  return a->fecha[2] < b->fecha[2];
				  
				  if (a->hora[0] != b->hora[0])
					  return a->hora[0] < b->hora[0];
				  
				  return a->hora[1] < b->hora[1];
			  });
}

string ListaTiquetes::listar() {
	std::stringstream oss;
	
	if (lista.empty()) {
		oss << "No hay tiquetes registrados.\n";
		return oss.str();
	}
	
	oss << "========== LISTA DE TIQUETES ==========\n\n";
	
	for (Tiquete* t : lista) {
		if (!t) continue;
		oss << t->to_string();
		oss << "---------------------------------------\n";
	}
	
	return oss.str();
}

string ListaTiquetes::compradosXusuario(int id_usuario) {
	ordenar_fecha_hora();
	
	std::stringstream oss;
	bool alguno = false;
	
	oss << "==== TIQUETES DEL USUARIO (ID: " << id_usuario << ") ====\n\n";
	
	for (Tiquete* t : lista) {
		if (!t) continue;
		if (t->get_id_usuario() == id_usuario) {
			alguno = true;
			oss << t->to_string();
			oss << "---------------------------------------\n";
		}
	}
	
	if (!alguno) {
		oss << "Este usuario no tiene tiquetes registrados.\n";
	}
	
	return oss.str();
}

Tiquete* ListaTiquetes::buscar(int codigo) {
	for(Tiquete* tiquete: this->lista){
		if(tiquete && tiquete->get_codigo() == codigo){ // usuario al principio para verificar que no sea null el usuario
			return tiquete;
		}
	}
	return nullptr;
}
