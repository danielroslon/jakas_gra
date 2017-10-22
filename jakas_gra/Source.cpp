#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;




int main()
{
	RenderWindow okno_aplikacji(VideoMode(1920, 1080, 32), "Naglowek okna", Style::Fullscreen);			//Stworzenie okna (uchwyt okna(rozmiar, g³êbia kolorów)) , nazwa okna, dodatkowe opcje np fullscreen)
	okno_aplikacji.clear(Color::White);																	//Wyczyszczenie okna na kolor bia³y

	okno_aplikacji.setFramerateLimit(120);


	Texture tekstura;																					//Obiekt przechowujacy tekstury		
	tekstura.loadFromFile("car.png");
	int i = 0;
	Vector2f v;
	v.x = 100;
	v.y = 0;

	Sprite patapon;
	patapon.setPosition(v);
	patapon.setTexture(tekstura);

	while(okno_aplikacji.isOpen())																		//G³ówna pêtla programu
	{
		Event zdarzenie;																				//Obiekt przechowujacy zdarzenia
			
		while (okno_aplikacji.pollEvent(zdarzenie))														//pollEvent - jesli jest jakies zdarzenie zwraca true
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)			//Jesli typ zdarzenia to nacisniece klawisza && wcisniety klawisz to Esc to nast¹pi zamkniêcie okna
			{
				okno_aplikacji.close();
			}
		}

		okno_aplikacji.clear(Color::White);
		okno_aplikacji.draw(patapon);
		patapon.move(v);
		Vector2f vv = patapon.getPosition();
		if (vv.x >= 1920)
		{
			i++;
			patapon.setPosition(Vector2f(0,i));
			if (vv.y >= 1080)
			{
				patapon.setPosition(Vector2f(0, 0));
			}
		}
		okno_aplikacji.display();																		//Wyswietlanie okna
	}
	

	return 0;
}
