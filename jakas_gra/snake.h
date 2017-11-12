#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <string>
#include "szablon_listy.h"

using namespace sf;

struct node
{
	RectangleShape element;
	node *next;
	node *prev;
	node(int _rozmiar) : element(Vector2f(_rozmiar, _rozmiar)), next(NULL), prev(NULL)
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
	int rozmiar;
public:
	snake(Vector2u);
	~snake();

	void ruch(Vector2u);
	void zmiana_kierunku(Event*);
	void rysowanie(RenderWindow*);
	void nowy_element();
	void usun_element();

	//Metody kontrolne
	void wypisywanie_pozycji();

	friend class gra;
};

