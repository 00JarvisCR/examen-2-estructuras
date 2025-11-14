#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>

class Utilidades {
private:
	static void clearInputBuffer();
public:
	static void limpiar(); // limpiar pantalla

	static void pausar(); // pausar pantalla
	
	static void pausar(const std::string& mensaje); // pausar pantalla con texto personalizado
	
	static int in_int(const std::string& mensaje); // para ingresar un entero con excepciones, pone el texto como parametro para no tener que hacer (cout <<) ni (cin >>)
	static int in_int(const std::string& mensaje, int min, int max); // lo mismo aca pero con limites
	
	static double in_float(const std::string& mensaje); // para ingresar un float con excepciones, pone el texto como parametro para no tener que hacer (cout <<) ni (cin >>)
	static double in_float(const std::string& mensaje, double min, double max); // lo mismo aca pero con limites de tamanio de texto
	
	static std::string in_string(const std::string& mensaje); // para ingresar un string con excepciones, pone el texto como parametro para no tener que hacer (cout <<) ni (cin >>)
	static std::string in_string(const std::string& mensaje, size_t min_length, size_t max_length); // lo mismo pero con limites
	
	static char in_char(const std::string& mensaje); // para ingresar un char con excepciones, pone el texto como parametro para no tener que hacer (cout <<) ni (cin >>)
	static char in_char(const std::string& mensaje, const std::string& caracteres_permitidos); // lo mismo pero solo acepta ciertos caracteres
};

#endif
