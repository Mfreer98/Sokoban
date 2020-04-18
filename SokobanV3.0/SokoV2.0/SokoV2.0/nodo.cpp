#include "nodo.h"


nodo::nodo(char elem, nodo* der, nodo* izq, nodo* arr, nodo* abj)
	:elem(elem), derecha(der), izquierda(izq), arriba(arr), abajo(abj) {}

void nodo::setDerecha(nodo* n) { this->derecha = n; }

void nodo::setIzquierda(nodo* n) { this->izquierda = n; }

void nodo::setArriba(nodo* n) { this->arriba = n; }

void nodo::setAbajo(nodo* n) { this->abajo = n; }

void nodo::setInfo(char c) { elem = c; }

nodo* nodo::getDerecha() { return derecha; }

nodo* nodo::getIzquierda() { return izquierda; }

nodo* nodo::getArriba() { return arriba; }

nodo* nodo::getAbajo() { return abajo; }

char nodo::getInfo() { return elem; }

nodo::~nodo() {}