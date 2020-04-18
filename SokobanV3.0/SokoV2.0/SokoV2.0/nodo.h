#ifndef NODO_H
#define NODO_H

#include<sstream>
#include"Utiles.h"

//Esta clase contiene una celda de la matriz a implementar
// Dicha matriz se formara con listas enlazadas en todas direcciones.
// De esta manera se facilitara la implementación de los movimientos del jugador.
class nodo {
public:
	nodo(char,nodo*, nodo*, nodo*, nodo*);
	
	void setDerecha(nodo*);
	void setIzquierda(nodo*);
	void setArriba(nodo*);
	void setAbajo(nodo*);
	void setInfo(char);

	nodo* getDerecha();
	nodo* getIzquierda();
	nodo* getArriba();
	nodo* getAbajo();
	char getInfo();
	

	virtual ~nodo();
private:
	nodo* derecha; //Apunta a su nodo a la derecha
	nodo* izquierda; //Apunta a su nodo a la izquierda
	nodo* arriba; //Apunta a su nodo arriba
	nodo* abajo; //Apunta a su nodo abajo
	char  elem; // el elemento contenido sera un char (#,$,@,.,!,' ')
				// Cada uno con un significado diferente.
};

#endif

