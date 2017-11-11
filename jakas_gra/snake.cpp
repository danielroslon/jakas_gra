#include "snake.h"



snake::snake(): direction("left")
{
	head = new node();
	head->element.setPosition(400,300);
	head->prev = new node();
	head->prev->next = head;
	head->prev->element.setPosition(420, 300);
	head->prev->element.setFillColor(Color::Blue);
	head->prev->prev = new node();
	head->prev->prev->next = head->prev;
	head->prev->prev->element.setPosition(440, 300);
	head->prev->prev->element.setFillColor(Color::Blue);
	tail=head->prev->prev;
}


snake::~snake()
{
}

void snake::zmiana_kierunku(Event *e)
{
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Right)
	{
		direction = "right";
	}
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Left)
	{
		direction = "left";
	}
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Down)
	{
		direction = "down";
	}
	if (e->type == e->KeyPressed && e->key.code == Keyboard::Up)
	{
		direction = "up";
	}
}
void snake::ruch(Event *e)
{
	node *wsk = tail;
	while (wsk != head)
	{
		wsk->element.setPosition(wsk->next->element.getPosition());
		wsk = wsk->next;
	}

	if (direction == "right")
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
	if (direction == "left")
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
	if (direction == "down")
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
	if (direction == "up")
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
		wsk = wsk->prev;
	}
	
}
void snake::nowy_element()
{
	tail->prev = new node();
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