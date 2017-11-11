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
			if (zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == Keyboard::S)
			{
				Sleep(5000);
			}
			s.zmiana_kierunku(&zdarzenie);
		}
		//Sleep(1000);
		s.ruch(&zdarzenie);
		s.rysowanie(&window);
		std::system("cls");
		std::cout << "x: " << s.head->element.getPosition().x << "\ny: " << s.head->element.getPosition().y << std::endl << std::endl;
		std::cout << "x: " << s.head->next->element.getPosition().x << "\ny: " << s.head->next->element.getPosition().y << std::endl << std::endl;
		std::cout << "x: " << s.head->next->next->element.getPosition().x << "\ny: " << s.head->next->next->element.getPosition().y << std::endl << std::endl;
		window.display();
	}
}