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