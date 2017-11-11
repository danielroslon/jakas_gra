#include "gra.h"



gra::gra(): window(VideoMode(800, 600, 32), "Gra", Style::None), s(window.getSize())
{
	
}


gra::~gra()
{
}


void gra::loop()
{
	while (window.isOpen())
	{
		window.clear(Color::Red);
		Event zdarzenie;

		while (window.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::Escape)
			{
				window.close();
			}
			s.zmiana_kierunku(&zdarzenie);
		}

		s.ruch(&zdarzenie);
		window.draw(s.kreska);
		std::system("cls");
		std::cout << "x: " << s.kreska.getPosition().x << "\ny: " << s.kreska.getPosition().y << std::endl;
		window.display();
	}
}