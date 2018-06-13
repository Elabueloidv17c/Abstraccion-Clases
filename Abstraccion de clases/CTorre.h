#pragma once
#include "CCuarto.h"
#include "Headers.h"

class CTorre : public CCuarto
{
public:
	bool m_cerrado;

	CTorre(string nombre, int piso, int norte, int sur, int este, int oeste, bool explorado, bool cerrado);
	CTorre();
	~CTorre() = default;
};

