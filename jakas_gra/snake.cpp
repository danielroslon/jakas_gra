#include "snake.h"



snake::snake(Vector2u v): direction("left"), rozmiar(v.y/30)
{
	head = new node(rozmiar);
	head->element.setPosition(v.x/2, v.y/2);
	head->prev = new node(rozmiar);
	head->prev->next = head;
	head->prev->element.setPosition(v.x / 2 + head->element.getSize().x, v.y/2);
	head->prev->element.setFillColor(Color::Blue);
	head->prev->prev = new node(rozmiar);
	head->prev->prev->next = head->prev;
	head->prev->prev->element.setPosition(v.x / 2 + head->element.getSize().x * 2, v.y/2);
	head->prev->prev->element.setFillColor(Color::Blue);
	tail=head->prev->prev;
}


snake::~snake()
{
}

void snake::zmiana_kierunku(Event *e)
{
	if (direction != "left" && e->type == e->KeyPressed && e->key.code == Keyboard::Right)
	{
		direction = "right";
	}
	if (direction != "right" && e->type == e->KeyPressed && e->key.code == Keyboard::Left)
	{
		direction = "left";
	}
	if (direction != "up" && e->type == e->KeyPressed && e->key.code == Keyboard::Down)
	{
		direction = "down";
	}
	if (direction != "down" && e->type == e->KeyPressed && e->key.code == Keyboard::Up)
	{
		direction = "up";
	}
}
void snake::ruch(Vector2u v)
{
	node *wsk = tail;
	while (wsk != head)
	{
		wsk->element.setPosition(wsk->next->element.getPosition());
		wsk = wsk->next;
	}

	if (direction == "right")
	{
		if (head->element.getPosition().x >= v.x - head->element.getSize().x)
		{
			head->element.setPosition(0, head->element.getPosition().y);
		}
		else
		{
			head->element.move(head->element.getSize().x, 0);
		}
	}
	if (direction == "left")
	{
		if (head->element.getPosition().x <= 0)
		{
			head->element.setPosition(v.x - head->element.getSize().x, head->element.getPosition().y);
		}
		else
		{
			head->element.move(-head->element.getSize().x, 0);
		}
	}
	if (direction == "down")
	{
		if (head->element.getPosition().y >= v.y - head->element.getSize().y)
		{
			head->element.setPosition(head->element.getPosition().x, 0);
		}
		else
		{
			head->element.move(0, head->element.getSize().y);
		}
	}
	if (direction == "up")
	{
		if (head->element.getPosition().y <= 0)
		{
			head->element.setPosition(head->element.getPosition().x, v.y - head->element.getSize().y);
		}
		else
		{
			head->element.move(0, -head->element.getSize().y);
		}
	}
}
void snake::rysowanie(RenderWindow* w)
{
	node *wsk = head;
	while (wsk != NULL)
	{
		w->draw(wsk->element);
		wsk = wsk->prev;
	}
	
}
void snake::nowy_element()
{
	tail->prev = new node(rozmiar);
	tail->prev->next = tail;
	tail = tail->prev;
}
void snake::usun_element()
{
	node *del = tail;
	if (head->prev->prev != del)
	{
		tail = tail->next;
		tail->prev = NULL;
		if (tail == head)
		{
			tail = head = NULL;
		}
		delete del;
	}

}

//Metody kontrolne
void snake::wypisywanie_pozycji()
{
	system("cls");
	node *wsk = head;
	int i = 0;
	while (wsk != NULL)
	{
		if (i == 5)
		{
			break;
		}
		std::cout << "x: " << wsk->element.getPosition().x << "\ny: " << wsk->element.getPosition().y << std::endl << std::endl;
		wsk = wsk->prev;
		i++;
	}
}