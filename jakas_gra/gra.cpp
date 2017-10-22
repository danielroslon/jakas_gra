#include "gra.h"

gra::gra(int _x, int _y, bool _fullscreen): resolution(_x,_y), fullscreen(_fullscreen)
{
	if (_fullscreen == true)
	{
		okno.create(VideoMode(_x, _y, 32), "gra", Style::Fullscreen);
	}
	else
	{
		okno.create(VideoMode(_x, _y), "gra");
	}
}
gra::~gra()
{
}

void gra::start()
{
	okno.clear(Color::White);

	while (okno.isOpen())
	{
		Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::KeyPressed && zdarzenie.key.code == Keyboard::Escape)
			{
				okno.close();
			}
		}
		okno.display();
	}
}
