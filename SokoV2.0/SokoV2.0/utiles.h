#include<conio.h>
#include<sstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>  

void imprimeCadena(std::string cadena) {
	std::cout << cadena;
}

std::string leerCadena() {
	std::string x;
	std::getline(std::cin, x);
	return x;
}

int leerEntero() {
	int n;
	bool continuar = true;
	while (true) {
		if (std::cin >> n) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			return n;
		}
		else {
			std::cerr << "Valor incorrecto.. digita UN NUMERO" << std::endl;
			std::cin.clear();
			std::cin.ignore(1024, '\n');
		}
	}

}

void limpiaPantalla() {
	system("cls");
}

void esperandoEnter() {
	std::cin.get();
}

void gotoxy(int x, int y) {

	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

void imprimeEntero(int numero) {
	std::cout << numero;
}