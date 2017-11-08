#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;


int main()
{
//Ustawienia okna
	RenderWindow okienko(VideoMode(800, 600, 32), "Aplikacja", Style::None);
	okienko.setFramerateLimit(120);

	RectangleShape kreska(Vector2f(800,5));
	kreska.setPosition(okienko.getSize().x / 2, okienko.getSize().y / 2);
	kreska.setFillColor(Color::Black);
	kreska.setOrigin(0,0);

	CircleShape kolo;
	kolo.setFillColor(Color::Blue);
	kolo.setRadius(200);
	kolo.setPosition(okienko.getSize().x / 2, okienko.getSize().y / 2);
	kolo.setOrigin(kolo.getPosition().x / 2 , kolo.getPosition().y / 2 + 50);
	kolo.setOutlineColor(Color::Black);
	kolo.setOutlineThickness(5);

//G³ówna pêtla

	char kierunek = 'p';

	while (okienko.isOpen())
	{
		Event zdarzenie;

		while (okienko.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == zdarzenie.Closed)
			{
				okienko.close();
			}
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::Escape)
			{
				okienko.close();
			}
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::Left)
			{
				kierunek = 'l';
			}
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::Right)
			{
				kierunek = 'p';
			}
		}

		kreska.setSize(Vector2f(200, 5));
		if (kierunek == 'p')
		{
			kreska.rotate(1);
		}
		if (kierunek == 'l')
		{
			kreska.rotate(-1);
		}
		okienko.clear(Color::Green);
		okienko.draw(kolo);
		okienko.draw(kreska);
		okienko.display();
	}


}
