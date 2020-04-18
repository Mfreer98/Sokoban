#include "Juego.h"

Juego::Juego()
{
	tablero = new lista();
	cajitas = new stack<char>();
	pasos = new queue<char>();
	gestor = new gestorArchivos();
}

Juego::~Juego()
{
	delete tablero;
	delete gestor;
}

void Juego::jugar(int i)
{
	instrucciones();
	bool aux = false;
	for (i; i < 3; i++)
	{
		limpiarContenerdores();
		limpiaPantalla();
		tablero->limpiarLista();
		if (i == 0)
		{
			cargarNivel1();
			aux = tablero->mover(cajitas, pasos);
		}
		else
		{
			if (i == 1) {

				cargarNivel2();
				aux = tablero->mover(cajitas, pasos);
			}
			else
			{
				if (i == 2)
				{
					cargarNivel3();
					aux = tablero->mover(cajitas, pasos);
				}
			}
		}
		if (!aux)
		{
			tablero->guardarArchivo(gestor);
			break;
		}
		else
		{
			if (aux && i != 2) {
				limpiaPantalla();
				imprimeCadena("GANASTE ");
				imprimeEntero(i + 1);
				imprimeCadena("\nEnter = siguente nivel\n Esc = Salir");
				char tecla;
				do
				{
					tecla = _getch();
				} while (tecla != ENTER && tecla != ESC);
				if (tecla == ESC)
				{
					break;
				}
			}
			else
			{
				limpiaPantalla();
				imprimeCadena("GANO TODOS LOS NIVELES\n");
				esperandoEnter();
			}
		}
	}

}

void Juego::MenuPrincipal()
{
	int ops;
	bool repite;

	// titulo y opciones;
	const char* titulo = "MENU PRINCIPAL\n";
	const char* opciones[] = { "Jugar", "Ver Repeticion","Cargar Partida", "Salir" };
	int n = 4; // cantidad de opciones
	do
	{
		ops = menu(titulo, opciones, n);
		switch (ops)
		{
		case 1: {
			jugar();
			break;
		}
		case 2: {
			verRepeticion();
			break; }
		case 3: {
			cargarPartida();
			break; }
		case 4: {
			ops = 0;
			break; }
		default:
			break;
		}
	} while (ops != 0);
}

void Juego::cargarNivel1()
{
	gestor->cargarNivel1(tablero, cajitas);
}

void Juego::cargarNivel2()
{
	gestor->cargarNivel2(tablero, cajitas);
}

void Juego::cargarNivel3()
{
	gestor->cargarNivel3(tablero, cajitas);
}

void Juego::verRepeticion()
{
	limpiaPantalla();
	if (!pasos->empty()) {

		int aux = tablero->getNivel();
		tablero->limpiarLista();
		if (aux == 1)
		{
			gestor->cargarNivel1(tablero, cajitas);
		}
		else
		{
			if (aux == 2) {
				gestor->cargarNivel2(tablero, cajitas);
			}
			else
			{
				if (aux == 3) {
					gestor->cargarNivel3(tablero, cajitas);
				}

			}
		}
		tablero->moverRepeticion(pasos);
		imprimeCadena("Salir");
		return;
	}
	else
	{
		limpiaPantalla();
		imprimeCadena("NO HAY REPETICION\n");
		esperandoEnter();
		return;
	}

}

void Juego::limpiarContenerdores()
{
	while (!pasos->empty())
	{
		pasos->pop();
	}
	while (!cajitas->empty()) {
		cajitas->pop();
	}
}

void Juego::cargarPartida()
{
	limpiaPantalla();
	limpiarContenerdores();
	tablero->limpiarLista();
	gestor->cargarCargarPartida(tablero, cajitas);
	if (tablero->esVacia())
	{
		limpiaPantalla();
		imprimeCadena("No hay partidas guardadas\n");
		esperandoEnter();
	}
	else
	{
		bool aux = false;
		imprimeCadena(tablero->toString());
		aux = tablero->mover(cajitas, pasos);
		if (!aux)
		{
			tablero->guardarArchivo(gestor);
			return;
		}
		else
		{
			limpiaPantalla();
			imprimeCadena("GANASTE ");
			imprimeEntero(tablero->getNivel());
			imprimeCadena("\nEnter = siguente nivel\n Esc = Salir");
			char tecla;
			do
			{
				tecla = _getch();
			} while (tecla != ENTER && tecla != ESC);
			if (tecla == ESC)
			{
				return;
			}
		}
		jugar(tablero->getNivel());
	}

}

int Juego::menu(const char* titulo, const char* opciones[], int n)
{
	int opcionElegida = 1;
	int tecla;
	int repite = true;
	do
	{
		limpiaPantalla();
		gotoxy(5, 3 + opcionElegida);
		imprimeCadena("-->");

		gotoxy(15, 2);
		imprimeCadena(titulo);

		for (int i = 0; i < n; i++)
		{
			gotoxy(10, 4 + i);
			imprimeEntero(i + 1);
			imprimeCadena(") ");
			imprimeCadena(opciones[i]);
		}
		do
		{
			tecla = _getch();
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
		switch (tecla)
		{
		case ABAJO: {
			opcionElegida++;
			if (opcionElegida > n)
			{
				opcionElegida = 1;
			}

			break; }

		case ARRIBA: {
			opcionElegida--;
			if (opcionElegida == 0)
			{
				opcionElegida = n;
			}
			break; }
		case ENTER: {repite = false;
			break; }


		default:
			break;
		}
	
	}
	while (repite);
	return opcionElegida;
}

void Juego::instrucciones()
{
	limpiaPantalla();
	imprimeCadena("\tINSTRUCCIONES\n");
	

	imprimeCadena(" Jugador =  @    \n");
	imprimeCadena(" Pared  =  #   \n");
	imprimeCadena(" Espacio para colocar una caja =    .    \n");
	imprimeCadena(" Caja  =   $    \n");
	imprimeCadena(" Caja ubicada en el destino (.) =  !     \n");
	imprimeCadena(" Espacio vacío =  Movimiento Libre    \n");
	imprimeCadena(" ESC para salir del juego   \n");
	imprimeCadena(" ENTER DOS VECES PARA CONTINUAR !!   \n");

	esperandoEnter();
}

