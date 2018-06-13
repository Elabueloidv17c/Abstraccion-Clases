#include "CVida.h"

CVida::CVida(int piso, int posicion, int valor)
{
	m_nombre = "medicina";
	m_tirado = 0;
	m_piso = piso;
	m_posicion = posicion;
	m_valor = valor;
}

CVida::CVida()
{
	m_nombre = "pocion de vida";
}

CVida::~CVida()
{

}

void CVida::Curar(CJugador* jugador)
{
	jugador->m_vida += m_valor;

	if (jugador->m_vida >= jugador->m_vidaMaxima)
	{
		jugador->m_vida = jugador->m_vidaMaxima;

		cout << "Usaste la " << m_nombre << " tus puntos de vida alcanzaron su valor maximo" << endl;
	}

	else
	{
		cout << "Usaste la " << m_nombre << " tu vida se ha incrementado en " << m_valor << " puntos" << endl;
	}
}
