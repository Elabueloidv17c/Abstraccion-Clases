#pragma once
#include "CLoot.h"

class CLlave : public CLoot
{
public:

	void Abrir(vector <CCuarto*> &torre, CJugador* jugador);

	CLlave(int posicion, int piso);
	CLlave();
	~CLlave();
};

