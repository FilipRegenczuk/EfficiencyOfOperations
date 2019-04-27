#pragma once
#include <string>



class Heap
{
public:
	int *array;			// wskaznik na dynamiczna tablice
	int n;				// ilosci elementow w kopcu

	Heap();
	virtual ~Heap();

	void push(int value);			// dodawanie do kopca
	void pop();						// usuwanie z kopca
	void search(int val);			// wyszukiwanie elementu
	void printHeap();				// wypisywanie kopca
	void popChosen(int val);		// usuwanie wybranego elementu
	void readFile(int val);			// wczytywanie wartosci z pliku
	void printBT(std::string sp, std::string sn, int v);

};