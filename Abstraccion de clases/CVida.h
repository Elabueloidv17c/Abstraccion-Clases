#pragma once
#include "CLoot.h"
#include "CJugador.h"

class CVida : public CLoot
{
public:
	int m_valor;

	void Curar(CJugador* jugador);

	CVida(int piso, int posicion, int valor);
	CVida();
	~CVida();
};

