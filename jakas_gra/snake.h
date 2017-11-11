#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;

struct node
{
	RectangleShape element;
	node *next;
	node *prev;
	node(Vector2u v) : element(Vector2f(20, 20)), next(NULL), prev(NULL)
	{
		element.setPosition(400, 300);
		element.setFillColor(Color::Blue);
	}
};

class snake
{
private:
	node *head;
	node *tail;
	char kierunek;
public:
	snake(Vector2u);
	~snake();

	void ruch(Event*);
	void zmiana_kierunku(Event*);
	void rysowanie(RenderWindow*);

	friend class gra;
};

