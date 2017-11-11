#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <string>

using namespace sf;

struct node
{
	RectangleShape element;
	node *next;
	node *prev;
	node() : element(Vector2f(20, 20)), next(NULL), prev(NULL)
	{
		element.setFillColor(Color::Blue);
	}
};

class snake
{
private:
	node *head;
	node *tail;
	std::string direction;
public:
	snake();
	~snake();

	void ruch(Event*);
	void zmiana_kierunku(Event*);
	void rysowanie(RenderWindow*);
	void nowy_element();
	void usun_element();


	//Metody kontrolne
	void wypisywanie_pozycji();

	friend class gra;
};

