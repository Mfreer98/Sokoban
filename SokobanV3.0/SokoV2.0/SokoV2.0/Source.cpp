#include<iostream>
#include<sstream>

using namespace std;


#include"Juego.h"
#include"gestorArchivos.h"
#include"lista.h"

int main() {
	Juego* j = new Juego();
	j->MenuPrincipal();

	delete j;
	return 0;
}