#include "List.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>

using namespace std;

List::List() 
{
	n = 0;				// poczatkowa konfiguracja - brak wartosci
	head = NULL;
	tail = NULL;
}

List::~List() 
{
	while (head)
		popHead();		// usuwanie elementów, dopoki istnieja
}

void List::pushFront(int value) 
{
	n++;
	ListElement *p = new ListElement;	// wskaznik na nowy element listy
	p->data = value;					// nadawanie wartosci p
	p->prev = NULL;						// element jest na przodzie, wiec nic nie ma przed nim
	p->next = head;						// po nim jest poprzedni pierwszy
	head = p;							// obecnym pierwszym jest nowy element

	if (p->next)				// jezli dodany element ma nastepnika...
		p->next->prev = p;		// ...nastepny wskazuje na niego jako na poprzednika
	else
		tail = p;				// w przeciwnym wypadku ten element jest tez ostatni
}

void List::pushBack(int value) 
{
	n++;
	ListElement *p = new ListElement;
	p->data = value;
	p->prev = tail;
	p->next = NULL;
	tail = p;

	if (p->prev)
		p->prev->next = p;
	else
		head = p;
}

void List::pop(ListElement *element) 
{
	if (element) 
	{
		if (element->prev)							// jezeli element posiada poprzednika...
			element->prev->next = element->next;	// ...poprzednik musi wskazywac na element bedacy po usuwanym jako na swojego nastepce
		else
			head = element->next; 

		if (element->next)
			element->next->prev = element->prev;
		else
			tail = element->prev;

		delete element;
		n--;					// zmniejszamy licznik elementow
	}
}

void List::popHead() 
{
	pop(head);
}

void List::popTail()
{
	pop(tail);
}

void List::printList() 
{
	ListElement *p;
	p = head;
	while (p) 
	{
		cout << " " << p->data;
		p = p->next;
	}
	cout << endl;
}

ListElement *List::findElement(int value)
{
	ListElement *p = head;
	while (p) 
	{
		if (p->data == value)
		{
			cout << "Element was found." << endl;
			return p;
		}
		p = p->next;
	}
	return NULL;				// jezli nic nie znaleziono
}

void List::popRandom(int index) 
{
	pop(indexFind(index));
}

void List::putBefore(int element, int value) 
{
	n++;
	ListElement *before = indexFind(element);		// znajduje wskaznik na element, przed ktorym mamy wstawic nowy
	if (before == head)
		pushFront(value);
	else 
	{
		ListElement *new_element = new ListElement;		// tworzymy nowy element
		new_element->data = value;						// nadanie mu odpowiedniej wartosci
		new_element->next = before;
		before->prev->next = new_element;
		before->prev = new_element;
	}
}

void List::readFile(int value)
{
	string str;
	fstream file("20000.txt", ios::in);
	if (file.good()) 
	{
		for (int i = 0; i < value; i++) 
		{
			getline(file, str);
			char tmp[sizeof(str)];
			strcpy_s(tmp, str.c_str());
			int number = atoi(tmp);
			pushBack(number);
		}
		file.close();
	}
}

ListElement *List::indexFind(int index) 
{
	int i = 0;
	ListElement *p = head;
	while (p) 
	{
		if (i == index) 
		{
			return p;
		}
		p = p->next;
		i++;
	}
	return NULL;
}