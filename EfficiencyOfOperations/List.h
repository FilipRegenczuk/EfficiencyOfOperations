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

	void pushFront(int value);
	void pushBack(int value);
	void pop(ListElement *element);				// funkcja usuwajaca element na podstawie wskaznika
	void popHead();
	void popTail();
	void printList();							// wypisywanie listy
	void popRandom(int value);
	void putBefore(int element, int value);		// dodaje po elemencie
	void readFile(int value);
	ListElement *indexFind(int index);			// szuka na podstawie kolejnosci w liscie
	ListElement *findElement(int value);		// znajdowanie wartosci na podstawie wskaznika
};