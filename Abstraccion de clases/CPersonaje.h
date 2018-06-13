#pragma once
#include "Headers.h"

class CPersonaje
{
public:

	bool m_vivo;
	int m_posicion;
	int m_piso;
	int m_ataque;
	int m_vida;
	int m_vidaMaxima;
	//No tiene interface porque los metodos que comparten no usan los mismos parametros
	CPersonaje() = default;
	virtual ~CPersonaje() = default;
};

