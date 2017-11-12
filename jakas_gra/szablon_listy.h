#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "food.h"

using namespace std;

template<typename T>class szablon_listy
{
private:
	struct element_listy
	{
		T element;
		element_listy *next;
		element_listy *prev;
		element_listy(T _element): element(_element), next(NULL), prev(NULL){}
	};
	element_listy *head;
	element_listy *tail;
	int ilosc_elementow;
public:
	szablon_listy(): head(NULL), tail(NULL), ilosc_elementow(0) {}

	void push(T _element)
	{
		if (head == NULL)
		{
			head = new element_listy(_element);
			tail = head;
		}
		else
		{
			tail->next = new element_listy(_element);
			tail->next->prev = tail;
			tail = tail->next;
		}
		ilosc_elementow++;
	}
	T pop()
	{	
		if (head)
		{
			element_listy *del = tail;
			if (head == tail)
			{
				T zwracana_wartosc = tail->element;
				tail = head = NULL;
				ilosc_elementow--;
				delete del;
				return zwracana_wartosc;
			}
			else
			{
				T zwracana_wartosc = tail->element;
				tail = tail->prev;
				tail->next = NULL;
				ilosc_elementow--;
				delete del;
				return zwracana_wartosc;
			}
		}
		T t;
		return t;
	}

	class iterator
	{
	private:
		szablon_listy &s;
		element_listy *index;

	public:
		iterator(szablon_listy _s): s(_s), index(s.head){}
		iterator(szablon_listy _s, bool b): s(_s), index(NULL){}


		bool operator!=(iterator a)
		{
			return (this->index != a.index);
		}
		T operator++(int)
		{
			T zwracana_wartosc = index->element;
			index = index->next;
			return zwracana_wartosc;
		}
		T operator*()
		{
			return this->index->element;
		}

	};


	void wypisz(sf::RenderWindow*);

};

