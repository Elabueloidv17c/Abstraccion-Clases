#pragma once
#include "Headers.h"
#include "CPersonaje.h"
#include "CJugador.h"
#include "CEnemigo.h"
#include "CCuarto.h"
#include "CTorre.h"
#include "CLoot.h"

class CMundo
{
public:
	vector <CCuarto*> m_habitaciones;
	vector <CEnemigo*> m_enemigos;
	vector <CLoot*> m_loot;
	CJugador* m_jugador;

	void Separador(vector <string>& palabras, const string& frase, char token);
	void Salir(string objetivo);
	void SalvarPartida(string objetivo);
	void NuevaPartida();
	void CargarPartida();
	bool HayEnemigo();
	void LoopDeJuego();
	void Adyacencia();
	void Intro();
	void Menu();
	void HUD();

	CMundo() = default;
	~CMundo();
};

