#include "snake.h"



snake::snake(Vector2u v): kreska(Vector2f(20,20)), kierunek('l')
{
	kreska.setPosition(0,0);
	kreska.setFillColor(Color::Blue);
}


snake::~snake()
{
}

void snake::zmiana_kierunku(Event *e)
{
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Right)
	{
		kierunek = 'p';
	}
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Left)
	{
		kierunek = 'l';
	}
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Down)
	{
		kierunek = 'd';
	}
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Up)
	{
		kierunek = 'g';
	}
}
void snake::ruch(Event *e)
{
	if (kierunek == 'p')
	{
		if (kreska.getPosition().x == 800 - kreska.getSize().x)
		{
			kreska.setPosition(0, this->kreska.getPosition().y);
		}
		else
		{
			kreska.move(20, 0);
		}
	}
	if (kierunek == 'l')
	{
		if (kreska.getPosition().x == 0)
		{
			kreska.setPosition(800 - kreska.getSize().x, this->kreska.getPosition().y);
		}
		else
		{
			kreska.move(-20, 0);
		}
	}
	if (kierunek == 'd')
	{
		if (kreska.getPosition().y == 600 - kreska.getSize().y)
		{
			kreska.setPosition(this->kreska.getPosition().x, 0);
		}
		else
		{
			kreska.move(0, 20);
		}
	}
	if (kierunek == 'g')
	{
		if (kreska.getPosition().y == 0)
		{
			kreska.setPosition(this->kreska.getPosition().x, 600 - kreska.getSize().y);
		}
		else
		{
			kreska.move(0, -20);
		}
	}
}
