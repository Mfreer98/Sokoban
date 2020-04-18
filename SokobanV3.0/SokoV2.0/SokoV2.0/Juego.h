#pragma once
#include"lista.h"
#include"gestorArchivos.h"
#include<queue>
#include<stack>


#define ENTER 13
class Juego
{
public:
	Juego();
	~Juego();
	void jugar(int = 0);
	void MenuPrincipal();
	void cargarNivel1();
	void cargarNivel2();
	void cargarNivel3();
	void verRepeticion();
	void limpiarContenerdores();
	void cargarPartida();
	int menu(const char* titulo, const char* opciones[], int n);
	void instrucciones();
private:
	lista* tablero;
	stack<char>* cajitas;
	queue<char>* pasos;
	gestorArchivos* gestor;
};

