#include "CEnemigo.h"
#include "CJugador.h"
#include "CLoot.h"
#include "Headers.h"

CEnemigo::CEnemigo(string nombre, int posicion, int piso, int ataque, int vida, int vidaMaxima, bool activo, bool vivo)
{
	m_nombre = nombre;
	m_vivo = vivo;
	m_posicion = posicion;
	m_piso = piso;
	m_ataque = ataque;
	m_vida = vida;
	m_vidaMaxima = vidaMaxima;
	m_activo = activo;
}

CEnemigo::~CEnemigo()
{

}

void CEnemigo::Atacar(CJugador* &jugador)
{
	if (m_vivo && m_activo && jugador->m_piso == m_piso && jugador->m_posicion == m_posicion)
	{
		jugador->m_vida -= m_ataque;
		cout << "El " << m_nombre << " redujo tus puntos de vida en " << m_ataque << endl;

		if (jugador->m_vida <= 0)
		{
			jugador->Morir();
		}
	}
}

void::CEnemigo::Morir(vector <CLoot*> &loot)
{
	m_activo = false;
	m_vivo = false;

	cout << "El " << m_nombre << " ha muerto." << endl;

	int j = 0;

	for (int i = 0; i < loot.size(); i++)
	{
		if (loot[i]->m_posicion == m_posicion && loot[i]->m_piso == m_piso)
		{
			loot[i]->m_tirado = true;
			j++;
		}
	}

	cout << "Ha soltado " << j << " objetos..." << endl;

	return;
}