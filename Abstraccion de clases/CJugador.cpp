#include "CJugador.h"
#include "CCuarto.h"
#include "CEnemigo.h"
#include "CLoot.h"
#include "CLlave.h"
#include "CVida.h"
#include "CMagia.h"
#include "Headers.h"

CJugador::CJugador(int posicion, int piso, int ataque, int vida, int vidaMaxima, int ataqueMagico, int magia, int magiaMaxima, int magiaCosto, bool vivo)
{
	m_posicion = posicion;
	m_piso = piso;
	m_ataque = ataque;
	m_vida = vida;
	m_vidaMaxima = vidaMaxima;
	m_ataqueMagico = ataqueMagico;
	m_magia = magia;
	m_magiaMaxima = magiaMaxima;
	m_magiaCosto = magiaCosto;
	m_vivo = vivo;
}

CJugador::~CJugador()
{
	for (int i = 0; i < m_inventario.size(); i++)
	{
		delete(m_inventario[i]);
	}
}

vector <int> CJugador::Encuentro(vector <CLoot*> &interaccion)
{
	vector <int> objetos;

	for (int i = 0; i < interaccion.size(); i++)
	{
		if (interaccion[i]->m_piso == m_piso && interaccion[i]->m_posicion == m_posicion)
		{
			objetos.push_back(i);
		}
	}

	return objetos;
}

int CJugador::Encuentro(vector <CEnemigo*> &interaccion)
{
	for (int i = 0; i < interaccion.size(); i++)
	{
		if (interaccion[i]->m_piso == m_piso && interaccion[i]->m_posicion == m_posicion)
		{
			return i;
		}
	}

	return -1;
}

int CJugador::Encuentro(vector <CCuarto*> &interaccion)
{
	for (int i = 0; i < interaccion.size(); i++)
	{
		if (interaccion[i]->m_piso == m_piso && interaccion[i]->m_posicion == m_posicion)
		{
			return i;
		}
	}
}

void CJugador::Atacar(vector <CEnemigo*> &enemigos, vector <CLoot*> &loot, string objetivo)
{
	int indice = Encuentro(enemigos);

	if (indice >= 0 && enemigos[indice]->m_vivo)
	{
		if (objetivo == enemigos[indice]->m_nombre)
		{
			enemigos[indice]->m_vida -= m_ataque;
			cout << "Atacaste al " << enemigos[indice]->m_nombre << " redujiste sus puntos de vida en " << m_ataque << endl;

			if (!(enemigos[indice]->m_activo))
			{
				enemigos[indice]->m_activo = true;
			}

			if (enemigos[indice]->m_vida <= 0)
			{
				enemigos[indice]->Morir(loot);
			}
		}

		else
		{
			cout << "No puedes atacar a " << enemigos[indice]->m_nombre << "..." << endl;
		}
	}

	else
	{
		cout << "Aqui no hay enemigos que puedas atacar..." << endl;
	}

	return;
}

void CJugador::Moverse(vector <CCuarto*> interaccion, string objetivo)
{
	int indice = Encuentro(interaccion);
	
	if (objetivo == "norte" && interaccion[indice]->m_norte >= 0)
	{
		for (int i = 0; i < interaccion.size(); i++)
		{
			if (interaccion[i]->m_sur == m_posicion && m_piso == interaccion[i]->m_piso)
			{
				cout << "Te moviste a " << interaccion[i]->m_nombre << endl;
				m_posicion = interaccion[i]->m_posicion;
				return;
			}
		}
	}

	else if (objetivo == "sur" && interaccion[indice]->m_sur >= 0)
	{
		for (int i = 0; i < interaccion.size(); i++)
		{
			if (interaccion[i]->m_norte == m_posicion && m_piso == interaccion[i]->m_piso)
			{
				cout << "Te moviste a " << interaccion[i]->m_nombre << endl;
				m_posicion = interaccion[i]->m_posicion;
				return;
			}
		}
	}

	else if (objetivo == "este" && interaccion[indice]->m_este >= 0)
	{
		for (int i = 0; i < interaccion.size(); i++)
		{
			if (interaccion[i]->m_oeste == m_posicion && m_piso == interaccion[i]->m_piso)
			{
				cout << "Te moviste a " << interaccion[i]->m_nombre << endl;
				m_posicion = interaccion[i]->m_posicion;
				return;
			}
		}
	}

	else if (objetivo == "oeste" && interaccion[indice]->m_oeste >= 0)
	{
		for (int i = 0; i < interaccion.size(); i++)
		{
			if (interaccion[i]->m_este == m_posicion && m_piso == interaccion[i]->m_piso)
			{
				cout << "Te moviste a " << interaccion[i]->m_nombre << endl;
				m_posicion = interaccion[i]->m_posicion;
				return;
			}
		}
	}

	else
	{
		cout << "No puedes ir hacia el " << objetivo << endl;
	}

	return;
}

void CJugador::Maldecir(vector <CEnemigo*> &enemigos, vector <CLoot*> &loot, string objetivo)
{
	int indice = Encuentro(enemigos);

	if (m_magia < m_magiaCosto)
	{
		cout << "No tienes suficiente poder para maldecir..." << endl;
		return;
	}

	if (indice >= 0 && enemigos[indice]->m_vivo)
	{
		if (objetivo == enemigos[indice]->m_nombre)
		{
			enemigos[indice]->m_vida -= m_ataqueMagico;
			cout << "Maldijiste al " << enemigos[indice]->m_nombre << " redujiste sus puntos de vida en " << m_ataqueMagico << endl;
			m_magia -= m_magiaCosto;

			if (!(enemigos[indice]->m_activo))
			{
				enemigos[indice]->m_activo = true;
			}

			if (enemigos[indice]->m_vida <= 0)
			{
				enemigos[indice]->Morir(loot);
			}
		}

		else
		{
			cout << "No puedes maldecir a " << enemigos[indice]->m_nombre << "..." << endl;
		}
	}

	else
	{
		cout << "Aqui no hay enemigos..." << endl;
	}

	return;
}

void CJugador::Morir()
{
	m_vivo = false;

	cout << "Moriste, la partida ha terminado, suerte para la proxima..." << endl;

	return;
}

void CJugador::Ayuda()
{
	cout << "Como jugar?" << endl <<
		"Para ejecutar cualquier accion debes introducir comandos de dos palabras separadas por un espacio" << endl <<
		"Que puedo hacer?" << endl <<
		"Ir: Esta accion sirve para desplazarte por el mapa, debes escribir el comando y una habitacion, por ejemplo:" << endl <<
		"    -Ir explanada" << endl <<
		"Subir/Bajar: Esta accion sirve para desplazarte por las escaleras, debes escribir el comando y la palabra 'escalera', por ejemplo:" << endl <<
		"    -Subir escalera" << endl <<
		"Explorar: Esta accion sirve para explorar la habitacion en la que te encuentras, con esto puedes encontrar objetos, por ejemplo:" << endl <<
		"    -Explorar sala" << endl <<
		"Tomar: Esta accion sirve para tomar los objetos que encuentres en las habitaciones y añadirlo a tu inventario, por ejemplo:" << endl <<
		"    -Tomar medicina" << endl <<
		"Usar: Esta accion sirve para usar los objetos que tengas en tu inventario, por ejemplo:" << endl <<
		"    -Usar medicina" << endl <<
		"Atacar: Esta accion sirve para atacar a los enemigos que encuentres en las habitaciones, por ejemplo:" << endl <<
		"    -Atacar gremlin" << endl <<
		"Maldecir: Esta accion sirve para lanzar una maldicion que infringe mucho daño al enemigo, por ejemplo:" << endl <<
		"    -Maldecir Goblin" << endl <<
		"Ver: Esta accion sirve para ver los elementos que ya tienes en tu inventario, por ejemplo:" << endl <<
		"    -Ver inventario" << endl <<
		"Salvar: Esta accion sirve para guardas tus progresos en el juego, por ejemplo:" << endl <<
		"    -Salvar partida" << endl <<
		"Cargar: Esta accion sirve para cargar una partida guardada y continuar jugando desde ahi, por ejemplo:" << endl <<
		"    -Cargar partida" << endl <<
		"Puedes usar mayusculas o minusculas a tu gusto, el juego reconocera las palabras de todos modos" << endl << endl <<
		"Nota: Si quieres volver a ver este menu, introduce el comando 'Ver ayuda'" << endl <<
		"----------------------------------------------------------------------------------------------------------------" << endl;

	return;
}

void CJugador::Bajar(vector <CCuarto*> interaccion, string objetivo)
{
	int indice = Encuentro(interaccion);

	if (objetivo == "escalera" || objetivo == "escaleras")
	{
		if (interaccion[indice]->m_posicion == 0 && m_piso > 1)
		{
			CTorre* torreActual = static_cast <CTorre*> (interaccion[indice]);

			for (int i = 0; i < interaccion.size(); i++)
			{
				if ((!torreActual->m_cerrado) && interaccion[i]->m_posicion == 0 && interaccion[i]->m_piso == (m_piso - 1))
				{
					m_piso = interaccion[i]->m_piso;
					cout << "Has bajado al piso " << interaccion[i]->m_piso << endl;
					return;
				}
			}

			cout << "No puedes bajar, la puerta esta cerrada..." << endl;
		}

		else
		{
			cout << "Aqui no hay " << objetivo << " que bajar" << endl;
		}
	}

	else
	{
		cout << "No puedo bajar " << objetivo << endl;
	}

	return;
}

void CJugador::Subir(vector <CCuarto*> interaccion, string objetivo)
{
	int indice = Encuentro(interaccion);
	int nPisos = 0;

	for (int i = 0; i < interaccion.size(); i++)
	{
		if (interaccion[i]->m_piso > nPisos)
		{
			nPisos = interaccion[i]->m_piso;
		}
	}

	if (objetivo == "escalera" || objetivo == "escaleras")
	{
		if (interaccion[indice]->m_posicion == 0 && m_piso < nPisos)
		{
			CTorre* torreActual = static_cast <CTorre*> (interaccion[indice]);

			for (int i = 0; i < interaccion.size(); i++)
			{
				if ((!torreActual->m_cerrado) && interaccion[i]->m_posicion == 0 && interaccion[i]->m_piso == (m_piso + 1))
				{
					m_piso = interaccion[i]->m_piso;
					cout << "Has subido al piso " << interaccion[i]->m_piso << endl;
					return;
				}
			}

			cout << "No puedes subir, la puerta esta cerrada..." << endl;
		}

		else
		{
			cout << "Aqui no hay " << objetivo << " que subir" << endl;
		}
	}

	else
	{
		cout << "No puedo subir " << objetivo << endl;
	}

	return;
}

void CJugador::Ver(string objetivo)
{
	if (objetivo == "inventario")
	{
		if (m_inventario.size() > 0)
		{
			cout << "Tienes esto en tu inventario: " << endl;
			for (int i = 0; i < m_inventario.size(); i++)
			{
				cout << m_inventario[i]->m_nombre;

				if (i < (m_inventario.size() - 1))
				{
					cout << ", ";
				}
			}
			
			cout << endl;
		}
		
		else
		{
			cout << "Tu inventario esta vacio" << endl;
		}
	}

	else if (objetivo == "ayuda")
	{
		Ayuda();
	}

	else
	{
		cout << "No puedo ver " << objetivo << "..." << endl;
	}

}

void CJugador::Explorar(vector <CLoot*> loot)
{
	bool encontrado = false;

	for (int i = 0; i < loot.size(); i++)
	{
		if (loot[i]->m_piso == m_piso && loot[i]->m_posicion == m_posicion && loot[i]->m_tirado)
		{
			if (!(encontrado))
			{
				cout << "Encontraste esto: "<< endl;
			}

			cout << "| " << loot[i]->m_nombre << "|";
			encontrado = true;
		}
	}

	if (!(encontrado))
	{
		cout << "No hay nada aqui..." << endl;
	}

	else
	{
		cout << endl;
	}
	
	return;
}

void CJugador::Tomar(vector <CLoot*> &loot, string objeto)
{
	vector <int> indices = Encuentro(loot);

	if (indices.size() > 0)
	{
		for (int i = 0; i < indices.size(); i++)
		{
			if (loot[indices[i]]->m_tirado && loot[indices[i]]->m_nombre == objeto)
			{
				m_inventario.push_back(loot[indices[i]]);

				cout << "Has tomado la " << loot[indices[i]]->m_nombre << endl;

				loot[indices[i]] = nullptr;
				loot.erase(loot.begin() + indices[i]);

				return;
			}
		}

		cout << "No puedes tomar " << objeto << endl;
	}

	else
	{
		cout << "Aqui no hay nada que puedas tomar..." << endl;
	}

	return;
}

void CJugador::Usar(vector <CCuarto*> cuartos, vector <CLoot*> loot, string objetivo)
{
	for (int i = 0; i < m_inventario.size(); i++)
	{
		int indice = Encuentro(cuartos);

		if (m_inventario[i]->m_nombre == objetivo)
		{
			if (m_posicion == 0 && cuartos[indice]->m_posicion == m_posicion)
				{

				if (m_inventario[i]->m_nombre == "llave")
				{
					CLlave* llave = static_cast <CLlave*> (m_inventario[i]);
					llave->Abrir(cuartos, this);
					m_inventario[i] = nullptr;
					m_inventario.erase(m_inventario.begin() + i);
				}

				else if (m_inventario[i]->m_nombre == "medicina")
				{
					CVida* pocion = static_cast <CVida*> (m_inventario[i]);
					pocion->Curar(this);
					m_inventario[i] = nullptr;
					m_inventario.erase(m_inventario.begin() + i);
				}

				else if (m_inventario[i]->m_nombre == "magia")
				{
					CMagia* pocion = static_cast <CMagia*> (m_inventario[i]);
					pocion->Activar(this);
					m_inventario[i] = nullptr;
					m_inventario.erase(m_inventario.begin() + i);
				}
				
				return;
			}

			cout << "No puedes usar " << objetivo << " aqui" << endl;
			return;
		}
	}

	cout << "No tienes " << objetivo << " en el inventario" << endl;

	return;
}