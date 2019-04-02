#pragma once


class Array
{
public:
	int* arr;		//wskaznik na dynamiczna tablice
	int n;			//ilosc elementow w tablicy

	Array();
	virtual ~Array();

	void pushBack(int elt);				//dodaj element z przodu
	void pushFront(int elt);			//dodaj element z tylu
	void pushRand(int elt, int ix);		//dodaj element w losowe miejsce
	void popBack();						//usun element z przodu
	void popFront();					//usun element z tylu
	void popRand(int elt);				//usun element z losowego miejsca
	int search(int elt);				//znajdz element
	void printArray();					// wypisz tablice
	void readFile(int value);			// wczytaj dane z pliku



};