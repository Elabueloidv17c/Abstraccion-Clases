#include "Headers.h"
#include "CMundo.h"
#include "CLlave.h"
#include "CMagia.h"
#include "CVida.h"

void CMundo::NuevaPartida()
{
	m_jugador = new CJugador();
	*m_jugador = CJugador::CJugador(1, 1, 10, 100, 100, 30, 0, 80, 20, 1);

	for (int i = 0; i < 13; i++)
	{
		m_habitaciones.push_back(new CCuarto());
	}

	*m_habitaciones[0] = CCuarto::CCuarto("entrada", 1, 1, -1, 2, -1, -1, 1);
	*m_habitaciones[1] = CCuarto::CCuarto("explanada", 2, 1, 1, -1, 4, -1, 0);
	*m_habitaciones[2] = CCuarto::CCuarto("almacen", 3, 1, -1, 4, -1, -1, 0);
	*m_habitaciones[3] = CCuarto::CCuarto("pasillo", 4, 1, 3, 5, -1, 2, 0);
	*m_habitaciones[4] = CCuarto::CCuarto("sala", 5, 1, 4, -1, -1, 0, 0);
	*m_habitaciones[5] = CCuarto::CCuarto("cocina", 1, 2, -1, 7, -1, 0, 0);
	*m_habitaciones[6] = CCuarto::CCuarto("balcon", 2, 2, -1, 0, -1, -1, 0);
	*m_habitaciones[7] = CCuarto::CCuarto("dormitorio", 3, 2, -1, -1, 0, -1, 0);
	*m_habitaciones[8] = CCuarto::CCuarto("bar", 4, 2, 0, 5, -1, -1, 0);
	*m_habitaciones[9] = CCuarto::CCuarto("calabozo", 5, 2, 4, -1, 7, 6, 0);
	*m_habitaciones[10] = CCuarto::CCuarto("arena", 6, 2, -1, -1, 5, -1, 0);
	*m_habitaciones[11] = CCuarto::CCuarto("armeria", 7, 2, 1, -1, -1, 5, 0);
	*m_habitaciones[12] = CCuarto::CCuarto("atalaya", 1, 3, 0, -1, -1, -1, 0);

	for (int i = 0; i < 3; i++)
	{
		m_habitaciones.push_back(new CTorre());
	}

	*m_habitaciones[13] = CTorre::CTorre("torre", 1, -1, -1, 5, -1, 0, 1);
	*m_habitaciones[14] = CTorre::CTorre("torre", 3, -1, 1, -1, -1, 0, 1);
	*m_habitaciones[15] = CTorre::CTorre("torre", 2, 2, 4, 1, 3, 0, 1);

	for (int i = 0; i < 9; i++)
	{
		m_enemigos.push_back(new CEnemigo());
	}

	*m_enemigos[0] = CEnemigo::CEnemigo("gremlin", 2, 1, 2, 20, 20, 0, 1);
	*m_enemigos[1] = CEnemigo::CEnemigo("goblin", 5, 1, 3, 40, 40, 0, 1);

	*m_enemigos[2] = CEnemigo::CEnemigo("goblin", 1, 2, 3, 40, 40, 0, 1);
	*m_enemigos[3] = CEnemigo::CEnemigo("goblin", 5, 2, 3, 40, 40, 1, 1);
	*m_enemigos[4] = CEnemigo::CEnemigo("troll", 6, 2, 8, 80, 80, 1, 1);
	*m_enemigos[5] = CEnemigo::CEnemigo("orco", 3, 2, 5, 60, 60, 0, 1);
	*m_enemigos[6] = CEnemigo::CEnemigo("orco", 4, 2, 5, 60, 60, 0, 1);
	*m_enemigos[7] = CEnemigo::CEnemigo("orco", 7, 2, 5, 60, 60, 1, 1);

	*m_enemigos[8] = CEnemigo::CEnemigo("dragon", 1, 3, 10, 100, 100, 1, 1);

	for (int i = 0; i < 21; i++)
	{
		m_loot.push_back(new CLoot());
	}


	CVida* curar0 = static_cast <CVida*> (m_loot[0]); *curar0 = CVida::CVida(1, 2, 15);
	CVida* curar1 = static_cast <CVida*> (m_loot[1]); *curar1 = CVida::CVida(1, 5, 15);
	CVida* curar2 = static_cast <CVida*> (m_loot[2]); *curar2 = CVida::CVida(2, 1, 15);
	CVida* curar3 = static_cast <CVida*> (m_loot[3]); *curar3 = CVida::CVida(2, 3, 15);
	CVida* curar4 = static_cast <CVida*> (m_loot[4]); *curar4 = CVida::CVida(2, 4, 15);
	CVida* curar5 = static_cast <CVida*> (m_loot[5]); *curar5 = CVida::CVida(2, 5, 15);
	CVida* curar6 = static_cast <CVida*> (m_loot[6]); *curar6 = CVida::CVida(2, 6, 15);
	CVida* curar7 = static_cast <CVida*> (m_loot[7]); *curar7 = CVida::CVida(2, 7, 15);

	CVida* curar8 = static_cast <CVida*> (m_loot[8]); *curar8 = CVida::CVida(1, 1, 15); curar8->m_tirado = true;
	CVida* curar9 = static_cast <CVida*> (m_loot[9]); *curar9 = CVida::CVida(2, 2, 15); curar9->m_tirado = true;
	CVida* curar10 = static_cast <CVida*> (m_loot[10]); *curar10 = CVida::CVida(3, 0, 15); curar10->m_tirado = true;

	CMagia* pocion3 = static_cast <CMagia*> (m_loot[11]); *pocion3 = CMagia::CMagia(2, 3, 10);
	CMagia* pocion4 = static_cast <CMagia*> (m_loot[12]); *pocion4 = CMagia::CMagia(2, 4, 10);
	CMagia* pocion5 = static_cast <CMagia*> (m_loot[13]); *pocion5 = CMagia::CMagia(2, 5, 10);
	CMagia* pocion6 = static_cast <CMagia*> (m_loot[14]); *pocion6 = CMagia::CMagia(2, 6, 10);
	CMagia* pocion7 = static_cast <CMagia*> (m_loot[15]); *pocion7 = CMagia::CMagia(2, 7, 10);
	CMagia* pocion2 = static_cast <CMagia*> (m_loot[16]); *pocion2 = CMagia::CMagia(2, 1, 10);
	CMagia* pocion1 = static_cast <CMagia*> (m_loot[17]); *pocion1 = CMagia::CMagia(1, 5, 10);
	CMagia* pocion0 = static_cast <CMagia*> (m_loot[18]); *pocion0 = CMagia::CMagia(1, 2, 10);

	srand(time(NULL));
	int random1 = rand() % (11 - 10);
	int random2 = rand() % (11 - 6);

	CLlave* llave1 = static_cast <CLlave*> (m_loot[19]); *llave1 = CLlave::CLlave(m_enemigos[random1]->m_posicion, 1);
	CLlave* llave2 = static_cast <CLlave*> (m_loot[20]); *llave2 = CLlave::CLlave(m_enemigos[random2 + 2]->m_posicion, 2);
}

CMundo::~CMundo()
{
	for (int i = 0; i < m_habitaciones.size(); i++)
	{
		delete (m_habitaciones[i]);
	}

	for (int i = 0; i < m_enemigos.size(); i++)
	{
		delete (m_enemigos[i]);
	}

	if (m_loot.size() > 0)
	{
		for (int i = 0; i < m_loot.size(); i++)
			delete (m_loot[i]);
	}
	
	delete (m_jugador);
}

void CMundo::LoopDeJuego()
{
	NuevaPartida();

	string palabra;
	int indice = 0;
	vector <string> comando;

	Intro();
	Menu();

	cin.ignore();
	cin.get();
	
	system("cls");

	while (true)
	{
		if (m_jugador->m_vida <= 0)
		{
			m_jugador->Morir();
			break;
		}

		if (!(m_enemigos[m_enemigos.size() - 1]->m_vivo))
		{
			cout << "Has cobrado venganza y reestablecido la paz en tu pueblo, muchas felicidades!" << endl
				 << "Espero que hayas disfrutado la experiencia, vuelve cuando quieras e intenta mejorar tu desempeño" << endl;

			break;
		}

		HUD();
		Adyacencia();

		cout << endl << "Ingresa un comando: ";
		getline(cin, palabra);
		Separador(comando, palabra, ' ');

		system("cls");
	
		if (comando.size() == 2)
		{
			if (comando[0] == "ir")
			{
				m_jugador->Moverse(m_habitaciones, comando[1]);
			}

			else if (comando[0] == "subir")
			{
				m_jugador->Subir(m_habitaciones, comando[1]);
			}

			else if (comando[0] == "bajar")
			{
				m_jugador->Bajar(m_habitaciones, comando[1]);
			}

			else if (comando[0] == "atacar")
			{
				m_jugador->Atacar(m_enemigos, m_loot, comando[1]);
			}

			else if (comando[0] == "maldecir")
			{
				m_jugador->Maldecir(m_enemigos, m_loot, comando[1]);
			}

			else if (comando[0] == "ver")
			{
				m_jugador->Ver(comando[1]);
			}

			else if (comando[0] == "explorar")
			{
				m_jugador->Explorar(m_loot);
			}

			else if (comando[0] == "tomar")
			{
				m_jugador->Tomar(m_loot, comando[1]);
			}

			else if (comando[0] == "usar")
			{
				m_jugador->Usar(m_habitaciones, m_loot, comando[1]);
			}

			else if (comando[0] == "salvar")
			{
				SalvarPartida(comando[1]);
			}

			else
			{
				cout << "Comando invalido, si quieres ver la lista de acciones teclear 'ver ayuda'" << endl;
			}
		}

		else if (comando.size() == 0)
		{
			cout << "No indrodujiste ningun comando, intentalo de nuevo" << endl;
		}

		else
		{
			cout << "Debes introducir comandos de dos palabras separadas por un espacio, intentalo de nuevo" << endl;
		}

		if (HayEnemigo())
		{
			m_enemigos[m_jugador->Encuentro(m_enemigos)]->Atacar(m_jugador);
		}

		comando.clear();
	}

	cin.get();

	return;
}

void CMundo::Intro()
{
	cout << "Tu pueblo lleva decadas sufriendo los ataques de un castillo infestado de monstruos." << endl;
	Sleep(500);
	cout << "Los guerreros del pueblo habian logrado defender su hogar hasta de los mas grandes orcos." << endl;
	Sleep(500);
	cout << "Pero esta ultima vez las cosas fueron diferentes... esta vez tu pueblo fue casi aniquilado." << endl;
	Sleep(500);
	cout << "Un gigantezco dragon lidero el ataque y mucha gente murio..." << endl << endl;
	Sleep(2000);
	cout << "La rabia se ha apoderado de ti y solo quieres terminar con esta pesadilla" << endl;
	Sleep(500);
	cout << "Tomas tus mejores armas y tu libro de maldiciones." << endl;
	Sleep(500);
	cout << "Es hora de emprender un viaje para terminar con esto de una vez por todas." << endl;
	Sleep(500);
	cout << "Tu mision es eliminar al dragon que lidera los ataques del castillo." << endl;
	Sleep(500);
	cout << "No importa lo que cueste, no saldras de ahi sin haber cumplido tu mision." << endl;
	Sleep(500);
	cout << "Estas cansado de tanta matanza, ahora llevaras la pesadilla hasta ellos..." << endl << endl;
	Sleep(2000);

	return;
}

void CMundo::Menu()
{
	cout << "Bienvenido a Knight's Revenge!" << endl << endl;
	cout << "Que quieres hacer?" << endl << "(Teclea el numero correspondiente a la opcion que desees)" << endl << endl;
	cout << "1.- Nueva partida" << endl;
	cout << "2.- Cargar partida" << endl;

	while (true)
	{
		string iniciador;
		cin >> iniciador;
		cout << endl;

		if (iniciador == "1")
		{
			cout << "Se ha creado una nueva partida..." << endl << endl;
			Sleep(1000);
			m_jugador->Ayuda();

			break;
		}

		if (iniciador == "2")
		{
			CargarPartida();
			cout << "Bienvenido de nuevo a la partida." << endl << endl;
			Sleep(1000);
			break;
		}

		else
		{
			cout << "Accion invalida, intentalo de nuevo" << endl;
		}

	}

	return;
}

void CMundo::HUD()
{
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	cout << "Vida:  " << m_jugador->m_vida << "/" << m_jugador->m_vidaMaxima << "    " << "Magia:" << m_jugador->m_magia << "/" << m_jugador->m_magiaMaxima 
		 << "    Piso: " << m_jugador->m_piso << "    Habitacion: " << m_habitaciones[m_jugador->Encuentro(m_habitaciones)]->m_nombre << "    " << "Llave:  ";

	bool exist = false;

	for (int i = 0; i < m_jugador->m_inventario.size(); i++)
	{
		if (m_jugador->m_inventario[i]->m_nombre == "llave")
		{
			cout << "Conseguida" << endl;
			exist = true;
		}
	}

	if (!exist)
	{
		cout << "No conseguida" << endl;
	}
	
	cout << "-------------------------------------        Enemigo        ------------------------------------------" << endl;

	int indice = m_jugador->Encuentro(m_enemigos);

	if (indice >= 0)
	{
		cout << "|" << m_enemigos[m_jugador->Encuentro(m_enemigos)]->m_nombre << "|     " << "Vida: " 
			 << m_enemigos[indice]->m_vida << "/" << m_enemigos[indice]->m_vidaMaxima << "    Activo:  ";
		
		if (m_enemigos[indice]->m_activo)
		{
			cout << "Si" << endl;
		}

		else
		{
			cout << "No" << endl;
		}
	}

	else
	{
		cout << "                                               ...                                                    " << endl;
	}

	cout << "------------------------------------------------------------------------------------------------------" << endl;

	return;
}

void CMundo::Salir(string objetivo)
{
	if (objetivo == "juego")
	{
		m_jugador->Morir();
	}

	else
	{
		cout << "Si quieres salir del juego debes introducir el comando 'cerrar juego'" << endl;
	}

	return;
}

void CMundo::Separador(vector <string>& palabras, const string& frase, char token)
{
	string palabra;

	istringstream separador(frase);

	while (getline(separador, palabra, token))
	{
		palabras.push_back(palabra);
	}

	for (int i = 0; i < palabras.size(); i++)
	{
		for (int j = 0; j < palabras[i].length(); j++)
		{
			palabras[i][j] = tolower(palabras[i][j]);
		}
	}

	return;
}

void CMundo::Adyacencia()
{
	vector <string> caminos;

	if (m_habitaciones[m_jugador->Encuentro(m_habitaciones)]->m_norte >= 0)
	{
		caminos.push_back("norte");
	}

	if (m_habitaciones[m_jugador->Encuentro(m_habitaciones)]->m_sur >= 0)
	{
		caminos.push_back("sur");
	}

	if (m_habitaciones[m_jugador->Encuentro(m_habitaciones)]->m_este >= 0)
	{
		caminos.push_back("este");
	}

	if (m_habitaciones[m_jugador->Encuentro(m_habitaciones)]->m_oeste >= 0)
	{
		caminos.push_back("oeste");
	}

	if (caminos.size() > 1)
	{
		cout << "  Puedes ir a estas direcciones: " << endl;
		
		for (int i = 0; i < caminos.size(); i++)
		{
			cout << "  | " << caminos[i] << " |  ";
		}
	}

	else if (caminos.size() == 1)
	{
		cout << "  Solo puedes ir al " << caminos[0] << endl;
	}

	else
	{
		cout << "  No puedes ir a ninguna parte..." << endl;
	}

	cout << endl << endl;

	caminos.clear();

	return;
}

void CMundo::SalvarPartida(string objetivo)
{
	if (objetivo == "partida")
	{
		ofstream* escritor = new ofstream;
		string nombre;
		cout << "Con que nombre quieres guardar tu partida?" << endl;
		getline(cin, nombre);
		escritor->open(nombre + ".txt");

		*escritor << m_jugador->m_piso << endl;
		*escritor << m_jugador->m_posicion << endl;
		*escritor << m_jugador->m_vida << endl;
		*escritor << m_jugador->m_magia << endl;
		//Enemigos
		for (int i = 0; i < m_enemigos.size(); i++)
		{
			*escritor << m_enemigos[i]->m_activo << endl;
		}

		for (int i = 0; i < m_enemigos.size(); i++)
		{
			*escritor << m_enemigos[i]->m_vivo << endl;
		}

		for (int i = 0; i < m_enemigos.size(); i++)
		{
			*escritor << m_enemigos[i]->m_vida << endl;
		}
		//Loot, primero escribo el tamaño del vector en el archivo
		*escritor << m_loot.size() << endl;

		for (int i = 0; i < m_loot.size(); i++)
		{
			if (m_loot[i]->m_nombre == "magia")
			{
				*escritor << -1 << endl; //-1 es mi token de "magia"
			}

			else if (m_loot[i]->m_nombre == "medicina")
			{
				*escritor << -2 << endl; //-2 es mi token de "medicina"
			}

			else
			{
				*escritor << -3 << endl; //-3 es mi token "llave"
			}
		}

		for (int i = 0; i < m_loot.size(); i++)
		{
			*escritor << m_loot[i]->m_piso << endl;
		}

		for (int i = 0; i < m_loot.size(); i++)
		{
			*escritor << m_loot[i]->m_posicion << endl;
		}

		for (int i = 0; i < m_loot.size(); i++)
		{
			*escritor << m_loot[i]->m_tirado << endl;
		}

		//Inventario, primero escribo el tamaño del vector en el archivo
		*escritor << m_jugador->m_inventario.size() << endl;

		for (int i = 0; i < m_jugador->m_inventario.size(); i++)
		{
			if (m_jugador->m_inventario[i]->m_nombre == "magia")
			{
				*escritor << -1 << endl; //-1 es mi token de "magia"
			}

			else if (m_jugador->m_inventario[i]->m_nombre == "medicina")
			{
				*escritor << -2 << endl; //-2 es mi token de "medicina"
			}

			else
			{
				*escritor << -3 << endl; //-3 es mi token "llave"
			}
		}

		for (int i = 0; i < m_jugador->m_inventario.size(); i++)
		{
			*escritor << m_jugador->m_inventario[i]->m_piso << endl;
		}

		for (int i = 0; i < m_jugador->m_inventario.size(); i++)
		{
			*escritor << m_jugador->m_inventario[i]->m_posicion << endl;
		}

		for (int i = 0; i <  m_jugador->m_inventario.size(); i++)
		{
			*escritor << m_jugador->m_inventario[i]->m_tirado << endl;
		}

		escritor->close();
		delete(escritor);

		cout << "Tu progreso se ha guardado satisfactoriamente" << endl;

		cin.get();
	}

	else
	{
		cout << "Para salvar tu progreso debes introducir el comando 'salvar partida'..." << endl;
	}
}

void CMundo::CargarPartida()
{
	vector <short> datos;
	string linea;
	ifstream* lector = new ifstream;

	cout << "Cual es el nombre de tu partida guardada?" << endl;
	cin.ignore();

	while (true)
	{
		getline(cin, linea);
		lector->open(linea + ".txt");

		if (lector->fail())
		{
			if (linea == "n")
			{
				cout << "Se ha creado una nueva partida..." << endl << endl;
				Sleep(1000);
				m_jugador->Ayuda();
				return;
			}
			cout << "No existe ninguna partida con ese nombre, intentalo de nuevo" << endl;
			cout << "Si quieres iniciar una nueva partida presiona la tecla 'n' y luego presiona enter" << endl;
			cin.ignore();
		}

		else
		{
			break;
		}

	}

	while (!lector->eof())
	{
		short contenido = 0;
		*lector >> contenido;
		datos.push_back(contenido);
	}

	lector->close();
	delete(lector);

	m_jugador->m_piso = datos[0];
	m_jugador->m_posicion = datos[1];
	m_jugador->m_vida = datos[2];
	m_jugador->m_magia = datos[3];

	int indice = 4;

	for (int i = 0; i < m_enemigos.size(); i++)
	{
		m_enemigos[i]->m_activo = datos[indice++];
	}

	for (int i = 0; i < m_enemigos.size(); i++)
	{
		m_enemigos[i]->m_vivo = datos[indice++];
	}

	for (int i = 0; i < m_enemigos.size(); i++)
	{
		m_enemigos[i]->m_vida = datos[indice++];
	}
	//Esto ajusta el vector al tamaño del vector en la partida guardada
	m_loot.clear();
	m_loot.resize(datos[indice++]);

	for (int i = 0; i < m_loot.size(); i++)
	{
		if (datos[indice] == - 1)
		{
			m_loot[i] = new CMagia;
			m_loot[i]->m_nombre = "magia";
			CMagia* magia = static_cast <CMagia*> (m_loot[i]);
			magia->m_valor = 10;
		}

		else if (datos[indice] == -2)
		{
			m_loot[i] = new CVida;
			m_loot[i]->m_nombre = "medicina";
			CVida* vida = static_cast <CVida*> (m_loot[i]);
			vida->m_valor = 15;
		}

		else
		{
			m_loot[i] = new CLlave;
			m_loot[i]->m_nombre = "llave";
		}
		
		indice++;
	}

	for (int i = 0; i < m_loot.size(); i++)
	{
		m_loot[i]->m_piso = datos[indice++];
	}

	for (int i = 0; i < m_loot.size(); i++)
	{
		m_loot[i]->m_posicion = datos[indice++];
	}

	for (int i = 0; i < m_loot.size(); i++)
	{
		m_loot[i]->m_tirado = datos[indice++];
	}
	//Esto ajusta el vector al tamaño del vector en la partida guardada
	m_jugador->m_inventario.clear();
	m_jugador->m_inventario.resize(datos[indice++]);
	
	for (int i = 0; i < m_jugador->m_inventario.size(); i++)
	{
		if (datos[indice] == -1)
		{
			m_jugador->m_inventario[i] = new CMagia;
			m_jugador->m_inventario[i]->m_nombre = "magia";
			CMagia* magia = static_cast <CMagia*> (m_jugador->m_inventario[i]);
			magia->m_valor = 10;
		}

		else if (datos[indice] == -2)
		{
			m_jugador->m_inventario[i] = new CVida;
			m_jugador->m_inventario[i]->m_nombre = "medicina";
			CVida* vida = static_cast <CVida*> (m_jugador->m_inventario[i]);
			vida->m_valor = 15;
		}

		else
		{
			m_jugador->m_inventario[i] = new CLlave;
			m_jugador->m_inventario[i]->m_nombre = "llave";
		}

		indice++;
	}

	for (int i = 0; i < m_jugador->m_inventario.size(); i++)
	{
		m_jugador->m_inventario[i]->m_piso = datos[indice++];
	}

	for (int i = 0; i < m_jugador->m_inventario.size(); i++)
	{
		m_jugador->m_inventario[i]->m_posicion = datos[indice++];
	}

	for (int i = 0; i < m_jugador->m_inventario.size(); i++)
	{
		m_jugador->m_inventario[i]->m_tirado = datos[indice++];
	}

	cout << "Partida cargada satisfactoriamente" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	return;
}

bool CMundo::HayEnemigo()
{
	for (int i = 0; i < m_enemigos.size(); i++)
	{
		if (m_jugador->m_posicion == m_enemigos[i]->m_posicion && m_jugador->m_piso == m_enemigos[i]->m_piso)
		{
			return true;
		}
	}

	return false;
}