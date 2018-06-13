#pragma once
#include "Headers.h"

class CLoot
{
public:
	string m_nombre;
	bool m_tirado;
	int m_posicion;
	int m_piso;

	CLoot() = default;
	virtual ~CLoot() = default;
};