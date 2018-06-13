#pragma once
#include "Headers.h"
#include "CTorre.h"
#include "CPersonaje.h"

class CCuarto;
class CEnemigo;
class CLoot;
class CMundo;

class CJugador : public CPersonaje
{
public:

	vector <CLoot*> m_inventario;
	int m_magia;
	int m_magiaMaxima;
	int m_magiaCosto;
	int m_ataqueMagico;

	vector <int> Encuentro(vector <CLoot*> &interaccion);
	int Encuentro(vector <CEnemigo*> &interaccion);
	int Encuentro(vector <CCuarto*> &interaccion);
	int Encuentro(vector <CTorre*> &interaccion);

	void Maldecir(vector <CEnemigo*> &enemigos, vector <CLoot*> &loot, string objetivo);
	void Atacar(vector <CEnemigo*> &enemigos, vector <CLoot*> &loot, string objetivo);
	void Moverse(vector <CCuarto*> interaccion, string objetivo);
	void Subir(vector <CCuarto*> interaccion, string objetivo);
	void Bajar(vector <CCuarto*> interaccion, string objetivo);
	void Tomar(vector <CLoot*> &loot, string objeto);
	void Explorar(vector <CLoot*> loot);
	void Usar(vector <CCuarto*> cuartos, vector <CLoot*> loot, string objetivo);
	void Morir();
	void Ver(string objetivo);
	void Ayuda();

	CJugador(int posicion, int piso, int ataque, int vida, int vidaMaxima, int ataqueMagico, int magia, int magiaMaxima, int magiaCosto, bool vivo);
	CJugador() = default;
	~CJugador();
};

