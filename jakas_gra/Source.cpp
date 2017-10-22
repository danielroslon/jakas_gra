#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;




int main()
{
	RenderWindow okno_aplikacji(VideoMode(1920, 1080, 32), "Naglowek okna", Style::Fullscreen);			//Stworzenie okna (uchwyt okna(rozmiar, g³êbia kolorów)) , nazwa okna, dodatkowe opcje np fullscreen)
	okno_aplikacji.clear(Color::White);																	//Wyczyszczenie okna na kolor bia³y
	
	while(okno_aplikacji.isOpen())																		//G³ówna pêtla programu
	{
		Event zdarzenie;																				//Zmienna przechowujaca zdarzenia
			
		while (okno_aplikacji.pollEvent(zdarzenie))														//pollEvent - jesli jest jakies zdarzenie zwraca true
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)			//Jesli typ zdarzenia to nacisniece klawisza && wcisniety klawisz to Esc to nast¹pi zamkniêcie okna
			{
				okno_aplikacji.close();
			}
		}

		okno_aplikacji.display();																		//Wyswietlanie okna
	}
	

	return 0;
}
