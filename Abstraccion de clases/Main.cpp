#include "CMundo.h"

int main()
{
	CMundo mundo;
	mundo.LoopDeJuego();
	cin.get();
	return 0;
}

/*
//Random:
tecnica de suma y multiplicacion,

#define MAX_rand 0xfffffffff
#define A (1235465768435132) numero aleatorio grande
#define B (1232156456875645) numero aleatorio grande

unsigned_int seed = 0

void Aleatorio(unsigned_int _s)
{
	seed = _s
}

int rand ()
{
	unsigned_int r = seed * A + B;
	seed = r
}

int MyRand (int min, int max)
{
	int rango = max - min;
	int r rand() % rango; //	int r rand() % rango + 1; (este es para inclusiva)

	return r+min;
}

//Reinterpret cast, para los vectores de este proyecto debe usarse dynamic cast (dynamic _cast<tipo>(dato);) si usas dinamico lo combierte en null
------------------------------------------------------------------------------------
Normalizar:
un numero es una asignacion (linea en plano cartesiano) 
*/