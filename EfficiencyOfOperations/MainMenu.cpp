/* Klasa mainMenu ma za zadanie wyœwietlaæ menu g³ówne programu oraz wywo³ywaæ funkcje struktur */

#include <iostream>
#include "MainMenu.h"

using namespace std;


MainMenu::MainMenu()
{
	exit = true;
}



void MainMenu::displayMenu()
{
	while (exit)
	{
		cout << "MENU GLOWNE" << endl;
		cout << "********************************************************\n" << endl;
		cout << "Wybierz strukture, na ktorej chcesz wykonywac operacje:" << endl;
		cout << "(1) Tablica" << endl;
		cout << "(2) Lista" << endl;
		cout << "(3) Kopiec" << endl;
		cout << "(4) Drzewo czerwono-czarne" << endl;
		cout << "(5) Aby wyjsc z programu\n" << endl;

		cout << "Wprowadz wartosc: ";
		cin >> var;

		switch (var)
		{
		case 1:
			displayArray();
			break;

		case 2:
			displayList();
			break;

		case 3:
			displayHeap();
			break;

		case 4:
			displayTree();
			break;

		case 27:
			exit = false;
			break;
		}
	}
}


void MainMenu::displayArray()
{
	bool exitA = true;
	char var;
	int elemNumber;

	// cout << "Z ilu elementow ma byc zbudowana tablica?"	<< endl;
	// cout << "Wprowadz wartosc: "							<< endl;
	// cin >> elemNumber;

	while (exitA)
	{
		cout << "TABLICA" << endl;
		cout << "********************************************************\n" << endl;
		cout << "Wybierz operacje:" << endl;
		cout << "(1) Dodaj elementy z przodu" << endl;
		cout << "(2) Dodaj elementy z tylu" << endl;
		cout << "(3) Dodaj elementy w losowe miejsce" << endl;
		cout << "(4) Usun elementy z przodu" << endl;
		cout << "(5) Usun elementy z tylu" << endl;
		cout << "(6) Usun elementy z losowego miejsca" << endl;
		cout << "(7) Wyszukaj element" << endl;
		cout << "(8) Wypisz tablice" << endl;
		cout << "(5) Wyjdz" << endl;

		cout << "Wprowadz wartosc: ";
		cin >> var;
	}
}


void MainMenu::displayList()
{

}


void MainMenu::displayHeap()
{

}

void MainMenu::displayTree()
{
}
