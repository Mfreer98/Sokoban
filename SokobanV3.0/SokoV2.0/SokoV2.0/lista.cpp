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



bool lista::moverAbajo()// se manda un true si y solo si la caja llga al punto.
{
	if (muneco->getAbajo()->getInfo() == '#' || muneco->getAbajo()->getInfo() == '.' ||
		muneco->getAbajo()->getInfo() == '!')
		return false;
	else
	{
		if (muneco->getAbajo()->getInfo() == ' ')
		{
			muneco->getAbajo()->setInfo('@');
			muneco->setInfo(' ');
			muneco = muneco->getAbajo();
			return false;
		}
		else
		{
			if (muneco->getAbajo()->getInfo() == '$')
				if (muneco->getAbajo()->getAbajo()->getInfo() == '#' || muneco->getAbajo()->getAbajo()->getInfo() == '$' ||
					muneco->getAbajo()->getAbajo()->getInfo() == '!')
					return false;
				else
				{
					if (muneco->getAbajo()->getAbajo()->getInfo() == ' ')
					{
						muneco->setInfo(' ');
						muneco->getAbajo()->setInfo('@');
						muneco = muneco->getAbajo();
						muneco->getAbajo()->setInfo('$');
						return false;
					}
					else
					{
						if (muneco->getAbajo()->getAbajo()->getInfo() == '.')
						{
							muneco->setInfo(' ');
							muneco->getAbajo()->setInfo('@');
							muneco = muneco->getAbajo();
							muneco->getAbajo()->setInfo('!');
							return true;
						}
					}
				}
		}
		return false;
	}
}

bool lista::moverArriba()
{

	if (muneco->getArriba()->getInfo() == '#' || muneco->getArriba()->getInfo() == '.' ||
		muneco->getArriba()->getInfo() == '!')
		return false;
	else
	{
		if (muneco->getArriba()->getInfo() == ' ')
		{
			muneco->getArriba()->setInfo('@');
			muneco->setInfo(' ');
			muneco = muneco->getArriba();
			return false;
		}
		else
		{
			if (muneco->getArriba()->getInfo() == '$')
				if (muneco->getArriba()->getArriba()->getInfo() == '#' || muneco->getArriba()->getArriba()->getInfo() == '$' ||
					muneco->getArriba()->getArriba()->getInfo() == '!')
					return false;
				else
				{
					if (muneco->getArriba()->getArriba()->getInfo() == ' ')
					{
						muneco->setInfo(' ');
						muneco->getArriba()->setInfo('@');
						muneco = muneco->getArriba();
						muneco->getArriba()->setInfo('$');
						return false;
					}
					else
					{
						if (muneco->getArriba()->getArriba()->getInfo() == '.')
						{
							muneco->setInfo(' ');
							muneco->getArriba()->setInfo('@');
							muneco = muneco->getArriba();
							muneco->getArriba()->setInfo('!');
							return true;
						}
					}
				}
		}
		return false;
	}
}

bool lista::moverIzquierda()
{

	if (muneco->getIzquierda()->getInfo() == '#' || muneco->getIzquierda()->getInfo() == '.' ||
		muneco->getIzquierda()->getInfo() == '!')
		return false;
	else
	{
		if (muneco->getIzquierda()->getInfo() == ' ')
		{
			muneco->getIzquierda()->setInfo('@');
			muneco->setInfo(' ');
			muneco = muneco->getIzquierda();
			return false;
		}
		else
		{
			if (muneco->getIzquierda()->getInfo() == '$')
				if (muneco->getIzquierda()->getIzquierda()->getInfo() == '#' || muneco->getIzquierda()->getIzquierda()->getInfo() == '$' ||
					muneco->getIzquierda()->getIzquierda()->getInfo() == '!')
					return false;
				else
				{
					if (muneco->getIzquierda()->getIzquierda()->getInfo() == ' ')
					{
						muneco->setInfo(' ');
						muneco->getIzquierda()->setInfo('@');
						muneco = muneco->getIzquierda();
						muneco->getIzquierda()->setInfo('$');
						return false;
					}
					else
					{
						if (muneco->getIzquierda()->getIzquierda()->getInfo() == '.')
						{
							muneco->setInfo(' ');
							muneco->getIzquierda()->setInfo('@');
							muneco = muneco->getIzquierda();
							muneco->getIzquierda()->setInfo('!');
							return true;
						}
					}
				}
		}
		return false;
	}
}

bool lista::moverDerecha()
{
	if (muneco->getDerecha()->getInfo() == '#' || muneco->getDerecha()->getInfo() == '.' ||
		muneco->getDerecha()->getInfo() == '!')
		return false;
	else
	{
		if (muneco->getDerecha()->getInfo() == ' ')
		{
			muneco->getDerecha()->setInfo('@');
			muneco->setInfo(' ');
			muneco = muneco->getDerecha();
			return false;
		}
		else
		{
			if (muneco->getDerecha()->getInfo() == '$')
				if (muneco->getDerecha()->getDerecha()->getInfo() == '#' || muneco->getDerecha()->getDerecha()->getInfo() == '$' ||
					muneco->getDerecha()->getDerecha()->getInfo() == '!')
					return false;
				else
				{
					if (muneco->getDerecha()->getDerecha()->getInfo() == ' ')
					{
						muneco->setInfo(' ');
						muneco->getDerecha()->setInfo('@');
						muneco = muneco->getDerecha();
						muneco->getDerecha()->setInfo('$');
						return false;
					}
					else
					{
						if (muneco->getDerecha()->getDerecha()->getInfo() == '.')
						{
							muneco->setInfo(' ');
							muneco->getDerecha()->setInfo('@');
							muneco = muneco->getDerecha();
							muneco->getDerecha()->setInfo('!');
							return true;
						}
					}
				}
		}
		return false;
	}
}

bool lista::mover(stack<char>* pila, queue<char>* cola)
{
	bool bandera = false;
	bool ops = false;
	//char tecla;
	while (!pila->empty() && bandera == false)
	{
		if (_kbhit()) {
			limpiaPantalla();
			char tecla = _getch();
			switch (tecla)
			{
			case ARRIBA: {
				ops = moverArriba();
				cola->push(tecla);
				if (ops)
				{
					pila->pop();
				}
				break;
			}
			case ABAJO: {
				ops = moverAbajo();
				cola->push(tecla);
				if (ops)
				{
					pila->pop();
				}
				break; }
			case DERECHA: {
				ops = moverDerecha();
				cola->push(tecla);
				if (ops)
				{
					pila->pop();
				}
				break; }
			case IZQUIERDA: {
				ops = moverIzquierda();
				cola->push(tecla);
				if (ops)
				{
					pila->pop();
				}
				break;
			}
			case ESC: {
				bandera = true;
				return false;
				break;
			}
			default:
				break;
			}
			imprimeCadena(toString());
		}
	}
	return true;
}

bool lista::moverRepeticion(queue<char>* cola)
{
	bool bandera = false;
	bool ops = false;
	//char tecla;
	while (!cola->empty())
	{

		limpiaPantalla();
		char tecla = cola->front();
		cola->pop();
		switch (tecla)
		{
		case ARRIBA: {
			ops = moverArriba();
			break;
		}
		case ABAJO: {
			ops = moverAbajo();
			break; }
		case DERECHA: {
			ops = moverDerecha();
			break; }
		case IZQUIERDA: {
			ops = moverIzquierda();
			break;
		}
		default:
			break;
		}
		imprimeCadena(toString());
		Sleep(150);
	}
	return true;
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

