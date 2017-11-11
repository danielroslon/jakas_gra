#include "snake.h"



snake::snake(Vector2u v): kierunek('l')
{
	head = new node(v);
	head->next = new node(v);
	head->next->prev = head;
	head->next->element.setPosition(420, 300);
	head->next->element.setFillColor(Color::Blue);
	head->next->next = new node(v);
	head->next->next->prev = head->next;
	head->next->next->element.setPosition(440, 300);
	head->next->next->element.setFillColor(Color::Blue);
	tail=head->next->next;
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
	node *wsk = tail;
	while (wsk != head)
	{
		wsk->element.setPosition(wsk->prev->element.getPosition());
		wsk = wsk->prev;
	}

	if (kierunek == 'p')
	{
		if (head->element.getPosition().x == 800 - head->element.getSize().x)
		{
			head->element.setPosition(0, this->head->element.getPosition().y);
		}
		else
		{
			head->element.move(20, 0);
		}
	}
	if (kierunek == 'l')
	{
		if (head->element.getPosition().x == 0)
		{
			head->element.setPosition(800 - head->element.getSize().x, this->head->element.getPosition().y);
		}
		else
		{
			head->element.move(-20, 0);
		}
	}
	if (kierunek == 'd')
	{
		if (head->element.getPosition().y == 600 - head->element.getSize().y)
		{
			head->element.setPosition(this->head->element.getPosition().x, 0);
		}
		else
		{
			head->element.move(0, 20);
		}
	}
	if (kierunek == 'g')
	{
		if (head->element.getPosition().y == 0)
		{
			head->element.setPosition(this->head->element.getPosition().x, 600 - head->element.getSize().y);
		}
		else
		{
			head->element.move(0, -20);
		}
	}

	

}
void snake::rysowanie(RenderWindow* w)
{
	node *wsk = head;
	while (wsk != NULL)
	{
		w->draw(wsk->element);
		wsk = wsk->next;
	}
	
}