#include <SFML/Graphics.hpp>
#include <cmath>


using namespace sf;

int main()
{
	Window okno_aplikacji;
	okno_aplikacji.create(VideoMode(1920,1080, 32), "Naglowek okna");
	
	

	while(okno_aplikacji.isOpen())
	{
		Event zdarzenie;


		while (okno_aplikacji.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
			{
				okno_aplikacji.close();
			}
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::B)
			{
				okno_aplikacji.setTitle("Nowa nazwa okienka");
			}
		}
		okno_aplikacji.display();
		
	}
	

	return 0;
}
