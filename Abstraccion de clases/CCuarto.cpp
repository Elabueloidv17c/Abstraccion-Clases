#include "CCuarto.h"
#include "Headers.h"

CCuarto::CCuarto(string nombre, int posicion, int piso, int norte, int sur, int este, int oeste, bool explorado)
{
	m_nombre = nombre;
	m_posicion = posicion;
	m_norte = norte;
	m_sur = sur;
	m_este = este;
	m_oeste = oeste;
	m_piso = piso;
	m_explorado = explorado;
}

CCuarto::~CCuarto()
{

}

