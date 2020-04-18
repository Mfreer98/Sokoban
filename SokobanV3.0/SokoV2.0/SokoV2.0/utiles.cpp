#include"utiles.h"
using namespace std;

void imprimeCadena(string cadena) {
	cout << cadena;
}

string leerCadena() {
	string x;
	getline(cin, x);
	return x;
}

int leerEntero() {
	int n;
	bool continuar = true;
	while (true) {
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "Valor incorrecto.. digita UN NUMERO" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}

}

void limpiaPantalla() {
	system("cls");
}

void esperandoEnter() {
	cin.get();
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
	cout << numero;
}