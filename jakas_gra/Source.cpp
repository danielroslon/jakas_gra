#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;




int main()
{
	RenderWindow okno_aplikacji(VideoMode(1920, 1080, 32), "Naglowek okna", Style::Fullscreen);			//Stworzenie okna (uchwyt okna(rozmiar, g��bia kolor�w)) , nazwa okna, dodatkowe opcje np fullscreen)
	okno_aplikacji.clear(Color::White);																	//Wyczyszczenie okna na kolor bia�y
	
	while(okno_aplikacji.isOpen())																		//G��wna p�tla programu
	{
		Event zdarzenie;																				//Zmienna przechowujaca zdarzenia
			
		while (okno_aplikacji.pollEvent(zdarzenie))														//pollEvent - jesli jest jakies zdarzenie zwraca true
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)			//Jesli typ zdarzenia to nacisniece klawisza && wcisniety klawisz to Esc to nast�pi zamkni�cie okna
			{
				okno_aplikacji.close();
			}
		}

		okno_aplikacji.display();																		//Wyswietlanie okna
	}
	

	return 0;
}
