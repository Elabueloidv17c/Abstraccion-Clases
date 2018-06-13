#pragma once
#include "Headers.h"
#include "CJugador.h"
#include "CPersonaje.h"

class CEnemigo : public CPersonaje
{
public:
	string m_nombre;
	bool m_activo;

	void Atacar(CJugador* &jugador);
	void Morir(vector <CLoot*> &loot);

	CEnemigo(string nombre, int posicion, int piso, int ataque, int vida, int vidaMaxima, bool activo, bool vivo);
	CEnemigo() = default;
	~CEnemigo();
};

