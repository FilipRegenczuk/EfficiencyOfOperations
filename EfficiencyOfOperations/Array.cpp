#include "Array.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>



Array::Array()
{
	n = 0;					// poczatkowo jest 0 danych
	arr = new int[n];		// inicjalizacja dynamicznej tablicy
}

Array::~Array()
{
	delete[] arr;			// zwolnienie miejsca zajmowanego przez tablice
}


void Array::pushBack(int elt)
{
	n++;								// zwiekszenie liczby elementow
	int * new_arr = new int[n - 1];		// inicjalizacja tymczasowej tablicy

	for (int i = 0; i < n - 1; i++)		// przepisywanie elementow z obecnej do tymczasowej tablicy
	{
		new_arr[i] = arr[i];
	}
	delete[] arr;						// zwalnianie miejsca na obecna tablice
	arr = new int[n];					// tworzenie nowej, wiekszej tablicy
	arr[n - 1] = elt;					// przypisywanie nowej zmiennej do odpowiedniego miejsca
	for (int i = 0; i < n - 1; i++)		// przepisywanie starych zmiennych
	{
		arr[i] = new_arr[i];
	}


	delete[] new_arr;			// usuwanie tymczasowej tablicy
}


void Array::pushFront(int elt)
{
	n++;								// zwiekszenie liczby elementow
	int * new_arr = new int[n - 1];		// inicjalizacja tymczasowej tablicy

	for (int i = 0; i < n - 1; i++)		// przepisywanie elementow z obecnej do tymczasowej tablicy
	{
		new_arr[i] = arr[i];
	}
	delete[] arr;						// zwalnianie miejsca na obecna tablice
	arr = new int[n];					// tworzenie nowej, wiekszej tablicy
	arr[0] = elt;						// przypisywanie nowej zmiennej do odpowiedniego miejsca
	for (int i = 1; i < n; i++)			// przepisywanie starych zmiennych
	{
		arr[i] = new_arr[i - 1];
	}
	delete[] new_arr;					// usuwanie tymczasowej tablicy
}


void Array::push(int elt, int ix)
{
	n++;								// zwiekszenie liczby elementow
	int * new_arr = new int[n - 1];		// inicjalizacja tymczasowej tablicy


	for (int i = 0; i < n - 1; i++)		// przepisywanie elementow z obecnej do tymczasowej tablicy
	{
		new_arr[i] = arr[i];
	}
	delete[] arr;					// zwalnianie miejsca na obecna tablice
	arr = new int[n];				// tworzenie nowej, wiekszej tablicy

	for (int i = 0; i < n; i++)		// przepisywanie starych zmiennych
	{
		if (i < ix)
		{
			arr[i] = new_arr[i];
		}
		if (i == ix)
		{
			arr[i] = elt;			// przypisywanie nowej zmiennej do odpowiedniego miejsca
		}
		if (i > ix)
		{
			arr[i] = new_arr[i - 1];	//przesuniecie sie na dalsze miejsca w wypadku znalezienia indeksu dla nowej zmiennej
		}
	}

	delete[] new_arr;				//usuwanie tymczasowej tablicy
}


int Array::search(int elt)
{
	int index = -1;					// pocatkowo wyszukany indeks to -1
	for (int i = 0; i < n; i++)		// szukanie lelementu zadanego argumentem funkcji
	{
		if (arr[i] == elt)
		{
			index = i;				// jesli element zostanie znaleziony to zwracany jest jego indeks
			break;
		}
	}

	return index;					// jesli nie zostanie znaleziony to zwracane jest -1
}


void Array::popBack()
{
	if (n > 0)							// jesli sa elementy w tablicy
	{
		n--;							// zmniejszenie ilosci elementow
		int * new_arr = new int[n];		// inicjalizacja tymczasowej tablicy
		for (int i = 0; i < n; i++)		// przepisywanie elementow z obecnej do tymczasowej tablicy
		{
			new_arr[i] = arr[i];
		}

		delete[] arr;				// zwalnianie miejsca na obecna tablice
		arr = new int[n];			// tworzenie nowej, wiekszej tablicy

		for (int i = 0; i < n; i++)		 // przepisywanie starych zmiennych
		{
			arr[i] = new_arr[i];
		}

		delete[] new_arr;				//usuwanie tymczasowej tablicy
	}
}


void Array::popFront()
{
	if (n > 0)							// jesli sa elementy w tablicy
	{
		n--;							// zmniejszenie ilosci elementow
		int * new_arr = new int[n];		// inicjalizacja tymczasowej tablicy
		for (int i = 0; i < n; i++)		// przepisywanie elementow z obecnej do tymczasowej tablicy
		{
			new_arr[i] = arr[i + 1];
		}

		delete[] arr;				// zwalnianie miejsca na obecna tablice
		arr = new int[n];			// tworzenie nowej, wiekszej tablicy

		for (int i = 0; i < n; i++)		// przepisywanie starych zmiennych
		{
			arr[i] = new_arr[i];
		}

		delete[] new_arr;		 //usuwanie tymczasowej tablicy
	}
}


void Array::popRand(int elt)
{
	if (n > 0)						// jesli sa elementy w tablicy
	{
		int ix = search(elt);			// wyszukiwanie indeksu usuwanego elementu
		n--;							// zmniejszenie ilosci elementow
		int * new_arr = new int[n];		// inicjalizacja tymczasowej tablicy
		for (int i = 0; i < n; i++)		// przepisywanie elementow z obecnej do tymczasowej tablicy
		{
			if (i < ix)
			{
				new_arr[i] = arr[i];	// ominiety zostaje indeks usuwanego elementu
			}
			if (i >= ix)
			{
				new_arr[i] = arr[i + 1];
			}

		}
		delete[] arr;			// zwalnianie miejsca na obecna tablice
		arr = new int[n];		// tworzenie nowej, wiekszej tablicy

		for (int i = 0; i < n; i++)		// przepisywanie starych zmiennych
		{
			arr[i] = new_arr[i];
		}

		delete[] new_arr;			// usuwanie tymczasowej tablicy
	}
}


void Array::printArray()		// wypisywanie wartosci z tablicy przy uzyciu petli for
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


void Array::readFile(int val)		// wczytywanie z pliku wartosci
{
	std::string str;
	std::fstream file("20000.txt", std::ios::in);		// otwieranie pliku
	if (file.good())
	{
		for (int i = 0; i < val; i++)		// wczytywanie okreslonej ilosci zmiennych
		{
			std::getline(file, str);				// wczytywanie zmiennej w formie string
			char temp[sizeof(str)];
			strcpy_s(temp, str.c_str());
			int number = atoi(temp);		// zamiana zmiennej na int
			pushFront(number);				// wpisywanie zmiennej do tablicy
		}
		file.close();				//zamykanie pliku
	}

}
