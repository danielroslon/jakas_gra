#include "szablon_listy.h"


void szablon_listy<food>::wypisz(sf::RenderWindow *w)
{
	element_listy *wsk = head;
	while (wsk != NULL)
	{
		wsk->element.rysowanie(w);
		wsk = wsk->next;
	}
}


void szablon_listy<food>::pop(Vector2f v)
{

	element_listy *wsk = head;
	while (wsk->element.getPosition() != v)
	{
		wsk = wsk->next;
	}

	if (head)
	{
		element_listy *del = wsk;
		if (head == wsk)
		{
			wsk = head = NULL;
			ilosc_elementow--;
			delete del;
		}
		else if (wsk->next != NULL)
		{
			wsk->prev->next = wsk->next;
			wsk = wsk->prev;
			ilosc_elementow--;
			delete del;
		}
		else
		{
			wsk = wsk->prev;
			wsk->next = NULL;
			ilosc_elementow--;
			delete del;
		}
	}
}