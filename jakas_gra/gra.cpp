#include "gra.h"



gra::gra(): window(VideoMode(800, 600, 32), "Snake", Style::None), s(window.getSize())
{
}


gra::~gra()
{
}


void gra::loop()
{
	while (window.isOpen())
	{
		//		Informacje o sterowaniu			///////////////////
		std::cout << "Strzalki: sterowanie\n";
		std::cout << "W: Dodanie nowego elementu\n";
		std::cout << "S: Usuniecie ostatniego elementu\n";
		std::cout << "P: Pauza 5 sekund\n\n";
		std::cout << "Esc: Wyjscie\n\n";
		///////////////////////////////////////////////////////////

		window.clear(Color::Red);
		Event zdarzenie;
		while (window.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::Escape)
			{
				window.close();
			}
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::P)
			{
				std::cout <<"\n\nPauza\n\n";
				Sleep(5000);
			}
			
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::W)
			{
				s.nowy_element();
			}
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::S)
			{
				s.usun_element();
			}

			s.zmiana_kierunku(&zdarzenie);
		}
		s.ruch(window.getSize());
		s.rysowanie(&window);
		s.wypisywanie_pozycji();

		window.display();
	}
}