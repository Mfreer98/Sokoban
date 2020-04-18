#include "gestorArchivos.h"


gestorArchivos::gestorArchivos() :
	nivel1("../nivel1.txt"), nivel2("../nivel2.txt"), nivel3("../nivel3.txt"), cargarPartida("../cargarPartida.txt") {}

gestorArchivos::~gestorArchivos() {}

//----------------------------------------------------------- INGRESA OBJETOS A LA LISTA NIVEL 1

void gestorArchivos::cargarNivel1(lista * lista, stack<char>* pila)
{
	abrirFlujoModoLecturaNivel1();
	char caracter;
	bool estado = false;
	string linea;

	while (archivo.good())
	{
		linea = recuperarString('\n');
		if (lista->esVacia())
		{
			for (int i = 0; i < linea.size(); i++)
			{
				if (linea[i] == '$') {
					pila->push('$');
				}

				caracter = linea[i];
				lista->insertar(caracter, false);
			}
		}
		else
		{
			caracter = linea[0];
			lista->insertar(caracter, true);
			for (int i = 1; i < linea.size(); i++)
			{
				if (linea[i] == '$') {
					pila->push('$');
				}
				caracter = linea[i];
				lista->insertar(caracter, false);
			}
		}
	}
	lista->setNivel(1);
	cerrarFlujoNivel1();
}
//----------------------------------------------------------- INGRESA OBJETOS A LA LISTA  NIVEL 2

void gestorArchivos::cargarNivel2(lista * lista, stack<char>* pila)
{
	abrirFlujoModoLecturaNivel2();
	char caracter;
	bool estado = false;
	string linea;


	while (archivo.good())
	{
		linea = recuperarString('\n');
		if (lista->esVacia())
		{
			for (int i = 0; i < linea.size(); i++)
			{
				if (linea[i] == '$') {
					pila->push('$');
				}

				caracter = linea[i];
				lista->insertar(caracter, false);
			}
		}
		else
		{
			caracter = linea[0];
			lista->insertar(caracter, true);
			for (int i = 1; i < linea.size(); i++)
			{
				if (linea[i] == '$') {
					pila->push('$');
				}
				caracter = linea[i];
				lista->insertar(caracter, false);
			}
		}
	}
	lista->setNivel(2);
	cerrarFlujoNivel2();
}
//----------------------------------------------------------- INGRESA OBJETOS A LA LISTA  NIVEL 3

void gestorArchivos::cargarNivel3(lista * lista, stack<char>* pila)
{
	abrirFlujoModoLecturaNivel3();
	char caracter;
	bool estado = false;
	string linea;


	while (archivo.good())
	{
		linea = recuperarString('\n');
		if (lista->esVacia())
		{
			for (int i = 0; i < linea.size(); i++)
			{
				if (linea[i] == '$') {
					pila->push('$');
				}

				caracter = linea[i];
				lista->insertar(caracter, false);
			}
		}
		else
		{
			caracter = linea[0];
			lista->insertar(caracter, true);
			for (int i = 1; i < linea.size(); i++)
			{
				if (linea[i] == '$') {
					pila->push('$');
				}
				caracter = linea[i];
				lista->insertar(caracter, false);
			}
		}
	}
	lista->setNivel(3);
	cerrarFlujoNivel3();
}

//----------------------------------------------------------- GUARDA ARCHIVO NIVEL 1

//----------------------------------------------------------- NIVEL 1
void gestorArchivos::abrirFlujoModoEscrituraNivel1() {
	archivo.open("nivel1.txt", ios::out);
}

void gestorArchivos::abrirFlujoModoLecturaNivel1() {
	archivo.open("nivel1.txt", ios::in);
}

void gestorArchivos::cerrarFlujoNivel1() {
	archivo.close();
}
//----------------------------------------------------------- NIVEL 2
void gestorArchivos::abrirFlujoModoEscrituraNivel2() {
	archivo.open("nivel2.txt", ios::out);
}
void gestorArchivos::abrirFlujoModoLecturaNivel2() {
	archivo.open("nivel2.txt", ios::in);
}
void gestorArchivos::cerrarFlujoNivel2() {
	archivo.close();
}
//----------------------------------------------------------- NIVEL 3
void gestorArchivos::abrirFlujoModoEscrituraNivel3() {
	archivo.open("nivel3.txt", ios::out);
}
void gestorArchivos::abrirFlujoModoLecturaNivel3() {
	archivo.open("nivel3.txt", ios::in);
}
void gestorArchivos::cerrarFlujoNivel3() {
	archivo.close();
}

//----------------------------------------------------------- RECUPERA Y GUARDA
void gestorArchivos::guardarString(string s) {
	archivo << s;
}

void gestorArchivos::guardarChar(char c)
{
	archivo << c;
}

string gestorArchivos::recuperarString(char delimitador) {
	string r;
	getline(archivo, r, delimitador);
	return r;
}
void gestorArchivos::guardarInt(int i)
{
	archivo << i;
}
//------------------------------Cargar Partida----------------


void gestorArchivos::cargarCargarPartida(lista* lista, stack<char>* pila)
{
	abrirFlujoModoLecturaCargarPartida();
	char caracter;
	bool estado = false;
	string linea;

	while (archivo.good())
	{
		linea = recuperarString('\n');
		if (linea.size() == 1)
		{
			lista->setNivel(stoi(linea));
		}
		else
		{
			if (lista->esVacia())
			{
				for (int i = 0; i < linea.size(); i++)
				{
					if (linea[i] == '$') {
						pila->push('$');
					}

					caracter = linea[i];
					lista->insertar(caracter, false);
				}
			}
			else
			{
				caracter = linea[0];
				lista->insertar(caracter, true);
				for (int i = 1; i < linea.size(); i++)
				{
					if (linea[i] == '$') {
						pila->push('$');
					}
					caracter = linea[i];
					lista->insertar(caracter, false);
				}
			}
		}
	}

	cerrarFlujoCargarPartida();

}

void gestorArchivos::abrirFlujoModoEscrituraCargarPartida()
{
	archivo.open("cargarPartida.txt", ios::out);
}

void gestorArchivos::abrirFlujoModoLecturaCargarPartida()
{
	archivo.open("cargarPartida.txt", ios::in);
}

void gestorArchivos::cerrarFlujoCargarPartida()
{
	archivo.close();
}
