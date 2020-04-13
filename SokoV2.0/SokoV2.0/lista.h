#ifndef LISTA_H
#define LISTA_H

#include"nodo.h"
#include<conio.h>
#include<windows.h>
#include<stack>
#include<queue>
#include<string>
#include"gestorArchivos.h"

using std::string;

#define ABAJO 80 
#define ARRIBA 72
#define DERECHA 77 
#define IZQUIERDA 75
#define ESC 27

class gestorArchivos;

class lista {

public:
	lista();
	~lista();
	//--------------------insertar------------------
	void insertar(char x, bool caso);
	void insertarPrimeraFila(bool caso, nodo*);
	void insertarOtrasFilas(bool caso, nodo*);
	//-----------------------------------------------
	void limpiarLista();
	string toString();
	bool esVacia();
	//------------------------------------------------
	char getMuneco() { return muneco->getInfo(); }
	void guardarArchivo(gestorArchivos*);
	void setNivel(int x) { nivel = x; }
	int getNivel() { return nivel; }
private:

	nodo* inicio;
	nodo* fila;
	nodo* columna;
	nodo* muneco;
	int nivel;

};

#endif