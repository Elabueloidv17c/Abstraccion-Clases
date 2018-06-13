#include "CJugador.h"
#include "CCuarto.h"
#include "CTorre.h"
#include "CLlave.h"

CLlave::CLlave(int posicion, int piso)
{
	m_nombre = "llave";
	m_tirado = 0;
	m_posicion = posicion;
	m_piso = piso;
}

CLlave::CLlave()
{
	m_nombre = "llave";
	m_tirado = 0;
}

CLlave::~CLlave() {}

void CLlave::Abrir(vector <CCuarto*> &cuartos, CJugador* jugador)
{
	int indice = jugador->Encuentro(cuartos);

	if (cuartos[indice]->m_posicion == 0)
	{
		CTorre* torre = static_cast <CTorre*> (cuartos[indice]);
		torre->m_cerrado = false;

		cout << "Has abierto la puerta, ahora puedes usar la escalera" << endl;
	}

	else
	{
		cout << "No puedes usar la llave aqui..." << endl;
	}
}
