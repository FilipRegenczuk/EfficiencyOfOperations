#pragma once

struct ListElement 
{
	ListElement *next;
	ListElement *prev;
	int data;				// dane przechowywane w elemencie
};

class List
{
public:
	ListElement *head;
	ListElement *tail;
	int n;					// ilosc elementow listy

	List();
	virtual ~List();

	void push_front(int value);
	void push_back(int value);
	void pop(ListElement *element);				// funkcja usuwajaca element na podstawie wskaznika
	void pop_head();
	void pop_tail();
	void show_list();							// wypisywanie listy
	void pop_random(int value);
	void put_before(int element, int value);	// dodaje po elemencie
	void read_file(int value);
	ListElement *index_find(int index);			// szuka na podstawie kolejnosci w liscie
	ListElement *find_element(int value);		// znajdowanie wartosci na podstawie wskaznika
};