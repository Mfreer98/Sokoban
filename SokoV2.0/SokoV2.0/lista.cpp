#include "lista.h"

lista::lista()
{
	inicio = nullptr;
	fila = nullptr;
	columna = nullptr;
	muneco = nullptr;
	nivel = 0;
}

lista::~lista()
{
}

void lista::insertar(char x, bool caso)
{
	nodo* nuevo = new nodo(x, nullptr, nullptr, nullptr, nullptr);
	if (nuevo->getInfo() == '@') {
		muneco = nuevo;
	}
	if (inicio == nullptr)// cuando la lista esta vacia
		inicio = nuevo;
	else
	{
		if (inicio->getAbajo() == nullptr)
			insertarPrimeraFila(caso, nuevo);
		else
		{
			insertarOtrasFilas(caso, nuevo);
		}
	}

}

void lista::insertarPrimeraFila(bool caso, nodo* nuevo)
{
	columna = inicio;
	if (!caso)
	{
		while (columna->getDerecha() != nullptr)
		{
			columna = columna->getDerecha();
		}
		columna->setDerecha(nuevo);
		nuevo->setIzquierda(columna);
	}
	else
	{

		inicio->setAbajo(nuevo);
		nuevo->setArriba(inicio);
	}

}

void lista::insertarOtrasFilas(bool caso, nodo* nuevo)
{

	fila = inicio;
	while (fila->getAbajo() != nullptr)
	{
		fila = fila->getAbajo();
	}
	if (caso) {
		fila->setAbajo(nuevo);
		nuevo->setArriba(fila);
	}
	else
	{
		nodo* aux = fila->getArriba();
		columna = fila;
		while (columna->getDerecha() != nullptr)
		{
			columna = columna->getDerecha();
			aux = aux->getDerecha();
		}
		columna->setDerecha(nuevo);
		nuevo->setIzquierda(columna);
		nuevo->setArriba(aux->getDerecha());
		aux = aux->getDerecha();
		aux->setAbajo(nuevo);
	}

}

void lista::limpiarLista()
{
	nodo* tmp;
	if (esVacia())
		return;
	else
	{
		fila = inicio;
		while (fila != nullptr)
		{
			columna = fila;
			fila = fila->getAbajo();

			while (columna != nullptr)
			{
				if (!columna->getDerecha())
				{
					delete columna;
					break;
				}
				else
				{
					tmp = columna;
					columna = columna->getDerecha();
					delete tmp;
				}

			}
		}
	}
	muneco = nullptr;
	inicio = nullptr;
	fila = nullptr;
	columna = nullptr;
}

string lista::toString() 
{
	std::stringstream s;
	fila = inicio;
	while (fila != nullptr)
	{
		columna = fila;
		while (columna != nullptr)
		{
			if (columna->getDerecha() == nullptr)
				s << columna->getInfo() << "\n";
			else
			{
				s << columna->getInfo();
			}
			columna = columna->getDerecha();
		}
		fila = fila->getAbajo();
	}

	return s.str();
}

bool lista::esVacia()
{
	if (inicio == nullptr)
	{
		return true;
	}
	return false;
}


void lista::guardarArchivo(gestorArchivos* gestor)
{
	int cont = 0;
	gestor->abrirFlujoModoEscrituraCargarPartida();
	fila = inicio;
	while (fila != nullptr)
	{
		columna = fila;
		while (columna != nullptr)
		{
			gestor->guardarChar(columna->getInfo());
			columna = columna->getDerecha();
		}
		gestor->guardarChar('\n');
		fila = fila->getAbajo();
		cont++;
	}
	gestor->guardarInt(nivel);
	gestor->cerrarFlujoCargarPartida();
}

