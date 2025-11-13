#include "Arbol.h"

Arbol::Arbol() {
	Nodo* Alajuela = new Nodo("Alajuela");
	Nodo* Rio_Segundo = new Nodo("Rio Segundo");
	Nodo* Heredia = new Nodo("Heredia");
	Nodo* San_Jose = new Nodo("San Jose");
	Nodo* Curridabat = new Nodo("Curridabat");
	Nodo* Cartago = new Nodo("Cartago");
	Nodo* San_Ramon = new Nodo("San Ramon");
	Nodo* Palmares = new Nodo("Palmares");
	Nodo* Naranjo = new Nodo("Naranjo");
	Nodo* Grecia = new Nodo("Grecia");
	
	// relaciones siguiente anterior
	Alajuela->sig = Rio_Segundo;
	Rio_Segundo->sig = Heredia;
	Rio_Segundo->sec = San_Ramon;
	Rio_Segundo->ant = Alajuela;
	Heredia->sig = San_Jose;
	Heredia->ant = Rio_Segundo;
	San_Jose->sig = Curridabat;
	San_Jose->ant = Heredia;
	Curridabat->sig = Cartago;
	Curridabat->ant = San_Jose;
	Cartago->ant = Curridabat;
	San_Ramon->sig = Palmares;
	San_Ramon->ant = Rio_Segundo;
	Palmares->sig = Naranjo;
	Palmares->ant = San_Ramon;
	Naranjo->sig = Grecia;
	Naranjo->ant = Palmares;
	Grecia->ant = Naranjo;
	
	// relaciones de distancia entre siguiente y anterior (KiloMetros)
	Alajuela->distancia_sig = 8;
	Rio_Segundo->distancia_sig = 25;
	Rio_Segundo->distancia_sec = 50;
	Rio_Segundo->distancia_ant = 8;
	Heredia->distancia_sig = 12;
	Heredia->distancia_ant = 25;
	San_Jose->distancia_sig = 7;
	San_Jose->distancia_ant = 12;
	Curridabat->distancia_sig = 19;
	Curridabat->distancia_ant = 7;
	Cartago->distancia_ant = 19;
	San_Ramon->distancia_sig = 8;
	San_Ramon->distancia_ant = 50;
	Palmares->distancia_sig = 9;
	Palmares->distancia_ant = 8;
	Naranjo->distancia_sig = 14;
	Naranjo->distancia_ant = 9;
	Grecia->distancia_ant = 14;
	
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

