#include "CMagia.h"
#include "CLoot.h"

CMagia::CMagia(int piso, int posicion, int valor)
{
	m_nombre = "magia";
	m_tirado = 0;
	m_piso = piso;
	m_posicion = posicion;
	m_valor = valor;
}

CMagia::CMagia()
{
	m_nombre = "pocion de magia";
}

CMagia::~CMagia() {}

void CMagia::Activar(CJugador* jugador)
{
	jugador->m_magia += m_valor;

	if (jugador->m_magia >= jugador->m_magiaMaxima)
	{
		jugador->m_magia = jugador->m_magiaMaxima;

		cout << "Usaste la " << m_nombre << " tus puntos de magia alcanzaron su valor maximo" << endl;
	}

	else
	{
		cout << "Usaste la " << m_nombre << " tu poder magico se ha incrementado en " << m_valor << " puntos" << endl;
	}
}
