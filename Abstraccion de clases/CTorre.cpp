#include "CTorre.h"
#include "Headers.h"

CTorre::CTorre(string nombre, int piso, int norte, int sur, int este, int oeste, bool explorado, bool cerrado)
{
	m_posicion = 0;
	m_nombre = nombre;
	m_piso = piso;
	m_norte = norte;
	m_sur = sur;
	m_este = este;
	m_oeste = oeste;
	m_explorado = explorado;
	m_cerrado = cerrado;
}

CTorre::CTorre()
{
	m_posicion = 0;
}