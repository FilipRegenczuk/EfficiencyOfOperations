#pragma once


class Array
{
public:
	int* arr;		// wskaznik na dynamiczna tablice
	int n;			// ilosc elementow w tablicy

	Array();
	virtual ~Array();

	void pushBack(int elt);				// dodaj element z przodu
	void pushFront(int elt);			// dodaj element z tylu
	void push(int elt, int ix);			// dodaj element na zadana pozycje
	void popBack();						// usun element z przodu
	void popFront();					// usun element z tylu
	void pop(int elt);					// usun element z zadanej pozycji
	int search(int elt);				// znajdz element
	void printArray();					// wypisz tablice
	void readFile(int value);			// wczytaj dane z pliku
};