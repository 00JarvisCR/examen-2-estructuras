#include "Utilidades.h"
#include <iostream>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <stdlib.h>
#endif

void Utilidades::limpiar() {
#ifdef _WIN32
	// Windows
	system("cls");
#else
	// Linux y otros sistemas Unix
	system("clear");
#endif
}

void Utilidades::pausar() {
	pausar("Presiona Enter para continuar...");
}

void Utilidades::clearInputBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Utilidades::pausar(const std::string& mensaje) {

	std::cout << mensaje;
	clearInputBuffer();
	std::cin.get();
}

int Utilidades::in_int(const std::string& mensaje) {
	int valor;
	while (true) {
		std::cout << mensaje;
		std::cin >> valor;
		
		if (std::cin.fail()) {
			std::cout << "Error: Por favor ingresa un número entero válido." << std::endl;
			clearInputBuffer();
		} else {
			//clearInputBuffer();
			return valor;
		}
	}
}

int Utilidades::in_int(const std::string& mensaje, int min, int max) {
	if (min > max) {
		throw std::invalid_argument("El valor mínimo no puede ser mayor que el máximo");
	}
	
	int valor;
	while (true) {
		valor = in_int(mensaje);
		
		if (valor < min || valor > max) {
			std::cout << "Error: El número debe estar entre " << min << " y " << max << "." << std::endl;
		} else {
			return valor;
		}
	}
}

double Utilidades::in_float(const std::string& mensaje) {
	double valor;
	while (true) {
		std::cout << mensaje;
		std::cin >> valor;
		
		if (std::cin.fail()) {
			std::cout << "Error: Por favor ingresa un número decimal válido." << std::endl;
			clearInputBuffer();
		} else {
			clearInputBuffer();
			return valor;
		}
	}
}

double Utilidades::in_float(const std::string& mensaje, double min, double max) {
	if (min > max) {
		throw std::invalid_argument("El valor mínimo no puede ser mayor que el máximo");
	}
	
	double valor;
	while (true) {
		valor = in_float(mensaje);
		
		if (valor < min || valor > max) {
			std::cout << "Error: El número debe estar entre " << min << " y " << max << "." << std::endl;
		} else {
			return valor;
		}
	}
}

std::string Utilidades::in_string(const std::string& mensaje) {
	std::string valor;
	std::cout << mensaje;
	std::cin >> valor;
	return valor;
}

std::string Utilidades::in_string(const std::string& mensaje, size_t min_length, size_t max_length) {
	if (min_length > max_length) {
		throw std::invalid_argument("La longitud mínima no puede ser mayor que la máxima");
	}
	
	std::string valor;
	while (true) {
		valor = in_string(mensaje);
		
		if (valor.length() < min_length || valor.length() > max_length) {
			std::cout << "Error: El texto debe tener entre " << min_length << " y " << max_length << " caracteres." << std::endl;
		} else {
			return valor;
		}
	}
}

char Utilidades::in_char(const std::string& mensaje) {
	std::string input;
	while (true) {
		input = in_string(mensaje);
		
		if (input.length() == 1) {
			return input[0];
		} else {
			std::cout << "Error: Por favor ingresa solo un carácter." << std::endl;
		}
	}
}

char Utilidades::in_char(const std::string& mensaje, const std::string& caracteres_permitidos) {
	if (caracteres_permitidos.empty()) {
		throw std::invalid_argument("La lista de caracteres permitidos no puede estar vacía");
	}
	
	char caracter;
	while (true) {
		caracter = in_char(mensaje);
		
		if (caracteres_permitidos.find(caracter) != std::string::npos) {
			return caracter;
		} else {
			std::cout << "Error: Carácter no permitido. Caracteres válidos: " << caracteres_permitidos << std::endl;
		}
	}
}
