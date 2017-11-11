#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <Windows.h>

#include "snake.h"
#include "food.h"
#include "szablon_listy.h"

using namespace sf;

class gra
{
private:
	RenderWindow window;
	snake s;
	szablon_listy<food> jedzenie;
public:
	gra();
	~gra();

	

	void loop();
};

