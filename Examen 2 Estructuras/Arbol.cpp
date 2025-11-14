#include "Arbol.h"
#include <sstream>

Arbol::Arbol() {
	this->Alajuela = new Nodo("Alajuela");
	this->Rio_Segundo = new Nodo("Rio Segundo");
	this->Heredia = new Nodo("Heredia");
	this->San_Jose = new Nodo("San Jose");
	this->Curridabat = new Nodo("Curridabat");
	this->Cartago = new Nodo("Cartago");
	this->San_Ramon = new Nodo("San Ramon");
	this->Palmares = new Nodo("Palmares");
	this->Naranjo = new Nodo("Naranjo");
	this->Grecia = new Nodo("Grecia");
	
	// relaciones siguiente anterior
	this->Alajuela->sig = Rio_Segundo;
	this->Rio_Segundo->sig = Heredia;
	this->Rio_Segundo->sec = San_Ramon;
	this->Rio_Segundo->ant = Alajuela;
	this->Heredia->sig = San_Jose;
	this->Heredia->ant = Rio_Segundo;
	this->San_Jose->sig = Curridabat;
	this->San_Jose->ant = Heredia;
	this->Curridabat->sig = Cartago;
	this->Curridabat->ant = San_Jose;
	this->Cartago->ant = Curridabat;
	this->San_Ramon->sig = Palmares;
	this->San_Ramon->ant = Rio_Segundo;
	this->Palmares->sig = Naranjo;
	this->Palmares->ant = San_Ramon;
	this->Naranjo->sig = Grecia;
	this->Naranjo->ant = Palmares;
	this->Grecia->ant = Naranjo;
	
	// relaciones de distancia entre siguiente y anterior (KiloMetros)
	this->Alajuela->distancia_sig = 8;
	this->Rio_Segundo->distancia_sig = 25;
	this->Rio_Segundo->distancia_sec = 50;
	this->Rio_Segundo->distancia_ant = 8;
	this->Heredia->distancia_sig = 12;
	this->Heredia->distancia_ant = 25;
	this->San_Jose->distancia_sig = 7;
	this->San_Jose->distancia_ant = 12;
	this->Curridabat->distancia_sig = 19;
	this->Curridabat->distancia_ant = 7;
	this->Cartago->distancia_ant = 19;
	this->San_Ramon->distancia_sig = 8;
	this->San_Ramon->distancia_ant = 50;
	this->Palmares->distancia_sig = 9;
	this->Palmares->distancia_ant = 8;
	this->Naranjo->distancia_sig = 14;
	this->Naranjo->distancia_ant = 9;
	this->Grecia->distancia_ant = 14;
	
}

Arbol::~Arbol() {
	delete Alajuela;
	delete Rio_Segundo;
	delete Heredia;
	delete San_Jose;
	delete Curridabat;
	delete Cartago;
	delete San_Ramon;
	delete Palmares;
	delete Naranjo;
	delete Grecia;
}

string Arbol::ver_nodos() {
	stringstream oss;
	
	oss << " 1. " << Alajuela->nombre << endl;
	oss << " 2. " << Rio_Segundo->nombre << endl;
	oss << " 3. " << Heredia->nombre << endl;
	oss << " 4. " << San_Jose->nombre << endl;
	oss << " 5. " << Curridabat->nombre << endl;
	oss << " 6. " << Cartago->nombre << endl;
	oss << " 7. " << San_Ramon->nombre << endl;
	oss << " 8. " << Palmares->nombre << endl;
	oss << " 9. " << Naranjo->nombre << endl;
	oss << "10. " << Grecia->nombre << endl;
	
	return oss.str();
}

