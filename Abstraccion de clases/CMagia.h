#pragma once
#include "CLoot.h"
#include "CJugador.h"

class CMagia : public CLoot
{
public:
	int m_valor;

	void Activar(CJugador* jugador);

	CMagia(int piso, int posicion, int valor);
	CMagia();
	~CMagia();
};

