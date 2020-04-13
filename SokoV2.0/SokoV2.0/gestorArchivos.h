#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include<iostream>
#include<string>
#include<fstream>
#include"lista.h"
#include<queue>
#include<stack>
using namespace std;
class lista;

class gestorArchivos{

private:

	fstream archivo;
	string nivel1;
	string nivel2;
	string nivel3;
	string cargarPartida;

public:
	gestorArchivos();
	~gestorArchivos();

	void cargarNivel1(lista*, stack<char>*);
	void cargarNivel2(lista *, stack<char>*);
	void cargarNivel3(lista *, stack<char>*);

	void cargarCargarPartida(lista*, stack<char>*);
	void guardarCargarPartida(lista*);
	void abrirFlujoModoEscrituraCargarPartida();
	void abrirFlujoModoLecturaCargarPartida();
	void cerrarFlujoCargarPartida();

	void abrirFlujoModoEscrituraNivel1();
	void abrirFlujoModoLecturaNivel1();
	void cerrarFlujoNivel1();

	void abrirFlujoModoEscrituraNivel2();
	void abrirFlujoModoLecturaNivel2();
	void cerrarFlujoNivel2();

	void abrirFlujoModoEscrituraNivel3();
	void abrirFlujoModoLecturaNivel3();
	void cerrarFlujoNivel3();

	void guardarString(string);
	void guardarChar(char);
	string recuperarString(char);
	void guardarInt(int);


};

#endif