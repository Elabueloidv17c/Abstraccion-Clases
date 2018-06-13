#pragma once
#include "Headers.h"

class CCuarto
{
public:
	string m_nombre;
	int m_posicion;
	int m_piso;
	bool m_explorado;
	int m_norte;
	int m_sur;
	int m_este;
	int m_oeste;

	CCuarto(string nombre, int posicion, int piso, int norte, int sur, int este, int oeste, bool explorado);
	CCuarto() = default;
	~CCuarto();
};

