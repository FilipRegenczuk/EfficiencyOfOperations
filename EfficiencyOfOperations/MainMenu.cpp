﻿/* Klasa MainMenu ma za zadanie wyswietlanie menu glowne programu oraz wywoluje funkcje struktur */

#include <iostream>
#include "MainMenu.h"
#include "Timer.h"
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "Tree.h"

using namespace std;


MainMenu::MainMenu()
{
	exit = true;
}

MainMenu::~MainMenu()
{
}



void MainMenu::displayMenu()
{
	while (exit)
	{
		cout << "                      MENU GLOWNE"								<< endl;
		cout << "********************************************************\n"	<< endl;
		cout << "Wybierz strukture, na ktorej chcesz wykonywac operacje:"		<< endl;
		cout << "(1) Tablica"													<< endl;
		cout << "(2) Lista"														<< endl;
		cout << "(3) Kopiec"													<< endl;
		cout << "(4) Drzewo czerwono-czarne"									<< endl;
		cout << "(5) Wyjdz z programu\n"										<< endl;

		cout << "Wprowadz liczbe: ";
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

		case 5:
			exit = false;
			break;
		}
	}
}


void MainMenu::displayArray()
{
	bool exitA = true;
	int varA;
	int elemNumber;
	Array array;

	cout << "Z ilu elementow ma byc zbudowana tablica?"	<< endl;
	cout << "Wprowadz wartosc: ";
	cin >> elemNumber;

	array.readFile(elemNumber);

	while (exitA)
	{
		cout << "\n                       TABLICA"								<< endl;
		cout << "********************************************************\n"	<< endl;
		cout << "Wybierz operacje:"												<< endl;
		cout << "(1)  Wypisz tablice"											<< endl;
		cout << "(2)  Dodaj element z przodu"									<< endl;
		cout << "(3)  Dodaj losowe elementy z przodu"							<< endl;
		cout << "(4)  Dodaj element z tylu"										<< endl;
		cout << "(5)  Dodaj losowe elementy z tylu"								<< endl;
		cout << "(6)  Dodaj element na zadana pozycje"							<< endl;
		cout << "(7)  Dodaj losowe elementy na losowe pozycje"					<< endl;
		cout << "(8)  Usun elementy z przodu"									<< endl;
		cout << "(9)  Usun elementy z tylu"										<< endl;
		cout << "(10) Usun element z zadanej pozycji"							<< endl;
		cout << "(11) Usun elementy z losowych pozycji"							<< endl;
		cout << "(12) Wyszukaj element"											<< endl;
		cout << "(13) Wroc do menu glownego\n"									<< endl;

		cout << "Wybrana operacja: ";
		cin >> varA;
		cout << endl;

		switch (varA)
		{
		// pierwsza operacja drukuje elementy tablicy
		case 1:
		{
			cout << "Tablica: ";		
			array.printArray();
		}
		break;

		// druga operacja zajmuje sie dodaniem z przodu elementu o wartosci podanej przez uzytkownika
		case 2:							
		{
			Timer timer;
			int newElem;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> newElem;

			timer.timerStart();					// w wypadku operacji dodawania, usuwania oraz wyszukiwania elementow w kazdej strukturze liczony jest jaczs wykonania operacji
			array.pushFront(newElem);
			timer.timerStop();
			cout << "Element zostal pomyslnie dodany" << endl << endl;
		}
		break;

		// trzecia operacja umozliwia dodawanie z przodu wybranej ilosci losowych elementow
		case 3:			
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;							// pobranie od uzytkownika liczby losowych liczb
			timer.timerStart();					// w wypadku operacji dodawania, usuwania oraz wyszukiwania elementow w kazdej strukturze liczony jest jaczs wykonania operacji

			if (tmp > 0)
			{

				for (int i = 0; i < tmp; i++)	// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
				{
					int rnd_num = rand() % 30000;
					array.pushFront(rnd_num);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie dodane" << endl << endl;
		}
		break;

		// czwarta operacja zajmuje sie dodaniem z tylu elementu o wartosci podanej przez uzytkownika
		case 4:
		{
			Timer timer;
			int newElem;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> newElem;

			timer.timerStart();					// w wypadku operacji dodawania, usuwania oraz wyszukiwania elementow w kazdej strukturze liczony jest jaczs wykonania operacji
			array.pushBack(newElem);
			timer.timerStop();
			cout << "Element zostal pomyslnie dodany" << endl << endl;
		}
		break;

		// piata operacja umozliwia dodawanie z tylu wybranej ilosci losowych elementow
		case 5:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;
			timer.timerStart();				// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					int rnd_num = rand() % 30000;
					array.pushBack(rnd_num);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie dodane" << endl << endl;
		}
		break;

		// szosta operacja zajmuje sie dodaniem elementu w wybranym miejscu i wartosci przez uzytkownika
		case 6:
		{
			Timer timer;
			int newElem;
			int position;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> newElem;
			cout << "Podaj pozycje elementu (pozycja liczona od 0): ";
			cin >> position;

			timer.timerStart();					// w wypadku operacji dodawania, usuwania oraz wyszukiwania elementow w kazdej strukturze liczony jest czas wykonania operacji
			array.push(newElem, position);
			timer.timerStop();
			cout << "Element zostal pomyslnie dodany" << endl << endl;
		}
		break;

		// siodma operacja umozliwia dodawanie w losowych miejscach losowych elementow
		case 7:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;
			timer.timerStart();				// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					int rnd_num = rand() % 30000;
					int rnd1 = rand() % elemNumber;
					array.push(rnd_num, rnd1);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie dodane" << endl << endl;
		}
		break;

		//  osma operacja zajmuje sie usuwaniem z przodu podanej przez uzytkownika liczby elementow
		case 8:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac?" << endl;
			cin >> tmp;
			timer.timerStart();			// ilosc usuwanych liczb jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					array.popFront();
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie usuniete" << endl << endl;
		}
		break;

		// dziewiata operacja zajmuje sie usuwaniem z tylu podanej przez uzytkownika liczby elementow
		case 9:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac?" << endl;
			cin >> tmp;
			timer.timerStart();			 // ilosc usuwanych liczb jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					array.popBack();
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie usuniete" << endl << endl;
		}
		break;

		// dziesiata operacja umozliwia usuwanie elementu z wybranej przez uzytkownika pozycji
		case 10:
		{
			Timer timer;
			int tmp;
			cout << "Z jakiej pozycji ma zostac usuniety element? (pozycja liczona od 0)" << endl;
			cin >> tmp;

			timer.timerStart();			// ilosc usuwanych liczb jest zadana przez uzytkownika
			array.pop(tmp);
			timer.timerStop();
			cout << "Element zostal pomyslnie usuniety" << endl << endl;
		}
		break;

		// jedenasta operacja zajmuje sie usuwaniem wybranej liczby elementow z losowych pozycji
		case 11:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac?" << endl;
			cin >> tmp;
			timer.timerStart();			// ilosc usuwanych liczb jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					int rnd = rand() % 30000;
					array.pop(rnd);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie usuniete" << endl << endl;
		}
		break;

		// dwunasta operacja pozwala wyszukiwac elementy po wartosci
		case 12:
		{
			Timer timer;
			int tmp;
			int found;
			cout << "Podaj wartosc szukanego elementu: ";
			cin >> tmp;

			timer.timerStart();			// uzytkownik podaje wyszukiwana wartosc
			found = array.search(tmp);
			cout << "Pozycja szukanego elementu (jeśli element nie istnieje zwrocone zostanie -1): " << found << endl;
			timer.timerStop();
		}
		break;

		// trzynasta operacja umozliwia powrot do menu glownego
		case 13:
		{
			exitA = false;
		}
		break;
		}
	}
}


void MainMenu::displayList()
{
	bool exitA = true;
	int varA;
	int elemNumber;
	List list;

	cout << "Z ilu elementow ma byc zbudowana lista?" << endl;
	cout << "Wprowadz wartosc: ";
	cin >> elemNumber;

	list.readFile(elemNumber);

	while (exitA)
	{
		cout << "\n                       LISTA"								<< endl;
		cout << "********************************************************\n"	<< endl;
		cout << "Wybierz operacje:"												<< endl;
		cout << "(1)  Wypisz liste"												<< endl;
		cout << "(2)  Dodaj element z przodu"									<< endl;
		cout << "(3)  Dodaj losowe elementy z przodu"							<< endl;
		cout << "(4)  Dodaj element z tylu"										<< endl;
		cout << "(5)  Dodaj losowe elementy z tylu"								<< endl;
		cout << "(6)  Dodaj element na zadana pozycje"							<< endl;
		cout << "(7)  Dodaj losowe elementy na losowe pozycje"					<< endl;
		cout << "(8)  Usun elementy z przodu"									<< endl;
		cout << "(9)  Usun elementy z tylu"										<< endl;
		cout << "(10) Usun element z zadanej pozycji"							<< endl;
		cout << "(11) Usun elementy z losowych pozycji"							<< endl;
		cout << "(12) Wyszukaj element"											<< endl;
		cout << "(13) Wroc do menu glownego\n"									<< endl;

		cout << "Wybrana operacja: ";
		cin >> varA;
		cout << endl;

		switch (varA)
		{
		// pierwsza operacja drukuje elementy listy
		case 1:
		{
			cout << "Lista: ";
			list.printList();
		}
		break;

		// druga operacja zajmuje sie dodaniem z przodu elementu o wartosci podanej przez uzytkownika
		case 2:
		{
			Timer timer;
			int newElem;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> newElem;

			timer.timerStart();					// w wypadku operacji dodawania, usuwania oraz wyszukiwania elementow w kazdej strukturze liczony jest jaczs wykonania operacji
			list.pushFront(newElem);
			timer.timerStop();
			cout << "Element zostal pomyslnie dodany" << endl << endl;
		}
		break;

		// trzecia operacja umozliwia dodawanie z przodu wybranej ilosci losowych elementow
		case 3:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;
			timer.timerStart();			// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					int rnd = rand() % 30000;
					list.pushFront(rnd);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie dodane" << endl << endl;
		}
		break;

		// czwarta operacja zajmuje sie dodaniem z tylu elementu o wartosci podanej przez uzytkownika
		case 4:
		{
			Timer timer;
			int newElem;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> newElem;

			timer.timerStart();			// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			list.pushBack(newElem);
			timer.timerStop();
			cout << "Element zostal pomyslnie dodany" << endl << endl;

		}
		break;

		// piata operacja umozliwia dodawanie z tylu wybranej ilosci losowych elementow
		case 5:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;
			timer.timerStart();			// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					int rnd = rand() % 30000;
					list.pushBack(rnd);
				}
			}
			timer.timerStop();
		}
		break;

		// szosta operacja zajmuje sie dodaniem elementu w wybranym miejscu i wartosci przez uzytkownika
		case 6:
		{
			Timer timer;
			int newElem;
			int position;
			cout << "Podaj wartosc nowego elementu: ";
			cin >> newElem;
			cout << "Podaj pozycje elementu (pozycja liczona od 0): ";
			cin >> position;

			timer.timerStart();					// w wypadku operacji dodawania, usuwania oraz wyszukiwania elementow w kazdej strukturze liczony jest czas wykonania operacji
			list.putBefore(position, newElem);
			timer.timerStop();
			cout << "Element zostal pomyslnie dodany" << endl << endl;
		}
		break;

		// siodma operacja umozliwia dodawanie w losowych miejscach losowych elementow
		case 7:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;
			timer.timerStart();

			for (int i = 0; i < tmp; i++)		// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			{
				int rnd = rand() % 30000;
				int rnd1 = rand() % list.n;
				list.putBefore(rnd1, rnd);
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie dodane" << endl << endl;
		}
		break;

		//  osma operacja zajmuje sie usuwaniem z przodu podanej przez uzytkownika liczby elementow
		case 8:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac?" << endl;
			cin >> tmp;				// uzytkownik podaje liczbe usuwanych elementow
			timer.timerStart();		

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					list.popHead();
				}
			}
			timer.timerStop();
		}
		break;

		// dziewiata operacja zajmuje sie usuwaniem z tylu podanej przez uzytkownika liczby elementow
		case 9:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac?" << endl;
			cin >> tmp;			 // uzytkownik podaje liczbe usuwanych elementow
			timer.timerStart(); 

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					list.popTail();
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie usuniete" << endl << endl;
		}
		break;

		// dziesiata operacja umozliwia usuwanie elementu z wybranej przez uzytkownika pozycji
		case 10:
		{
			Timer timer;
			int tmp;
			cout << "Z jakiej pozycji ma zostac usuniety element? (pozycja liczona od 0)" << endl;
			cin >> tmp;

			timer.timerStart();			// ilosc usuwanych liczb jest zadana przez uzytkownika
			list.popRandom(tmp);
			timer.timerStop();
			cout << "Element zostaly pomyslnie usuniety" << endl << endl;
		}
		break;

		// jedenasta operacja zajmuje sie usuwaniem wybranej liczby elementow z losowych pozycji
		case 11:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac?" << endl;
			cin >> tmp;						 // uzytkownik podaje liczbe usuwanych elementow
			timer.timerStart();

			for (int i = 0; i < tmp; i++)
			{
				int rnd = rand() % elemNumber;
				list.popRandom(rnd);
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie usuniete" << endl << endl;
		}
		break;

		// dwunasta operacja pozwala wyszukiwac elementy po wartosci
		case 12:
		{
			Timer timer;
			int tmp;
			cout << "Podaj wartosc szukanego elementu: " << endl;
			cin >> tmp;					// uzytkownik podaje wyszukiwany element

			timer.timerStart();		
			list.findElement(tmp);
			timer.timerStop();
		}
		break;

		// trzynasta operacja umozliwia powrot do menu glownego
		case 13:
		{
			exitA = false;
		}
		break;
		}
	}
}


void MainMenu::displayHeap()
{
	bool exitA = true;
	int varA;
	int elemNumber;
	Heap heap;
	cout << "Z ilu wartosci ma zostac utworzony kopiec: " << endl;
	cin >> elemNumber;
	heap.readFile(elemNumber);

	while (exitA)
	{
		cout << "\n                        KOPIEC"								<< endl;
		cout << "********************************************************\n"	<< endl;
		cout << "Wybierz operacje: "											<< endl;
		cout << "(1) Wypisz kopiec"												<< endl;
		cout << "(2) Dodaj element"												<< endl;
		cout << "(3) Dodaj losowe elementy"										<< endl;
		cout << "(4) Usun elementy"												<< endl;
		cout << "(5) Usun wybrany element"										<< endl;
		cout << "(6) Wyszukaj element"											<< endl;
		cout << "(7) Wroc do menu glownego\n"									<< endl;
		
		cout << "Wybrana operacja: ";
		cin >> varA;
		cout << endl;

		switch (varA)
		{
		// pierwsza operacja drukuje elementy kopca
		case 1:
		{
			cout << "Kopiec: ";
			heap.printBT("  ", "  ", 0);
		}
		break;

		// druga operacja zajmuje sie dodaniem elementu o wartosci podanej przez uzytkownika
		case 2:
		{
			Timer timer;
			int newElem;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> newElem;

			timer.timerStart();			// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			heap.push(newElem);
			timer.timerStop();
			cout << "Element zostal pomyslnie dodany" << endl << endl;
		}
		break;

		// trzecia operacja umozliwia dodawanie wybranej ilosci losowych elementow
		case 3:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;
			timer.timerStart();			// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					int rnd = rand() % 30000;
					heap.push(rnd);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie dodane" << endl << endl;
		}
		break;

		// czwarta operacja zajmuje sie usuwaniem podanej przez uzytkownika liczby elementow
		case 4:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac?" << endl;
			cin >> tmp;				//uzytkownik podaje liczbe usuwanych wartosci

			if (tmp > elemNumber)
			{
				tmp = elemNumber;
			}

			timer.timerStart();

			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					heap.pop();
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie usuniete" << endl << endl;
		}
		break;

		// piata operacja umozliwia usuwanie wybranego przez uzytkownika elementu
		case 5:
		{
			Timer timer;
			int tmp;
			cout << "Jaki element chcesz usunac?" << endl;
			cin >> tmp;

			timer.timerStart();			// istnieje mozliwosc usuniecia wybranego elementu
			heap.popChosen(tmp);
			timer.timerStop();
			cout << "Element zostal pomyslnie usuniety" << endl << endl;
		}
		break;

		// szosta operacja pozwala wyszukiwac elementy po wartosci
		case 6:
		{
			Timer timer;
			int tmp;
			cout << "Jaki element chcesz wyszukac?" << endl;
			cin >> tmp;

			timer.timerStart();		// uzytkownik podaje wyszukiwany element
			heap.search(tmp);
			timer.timerStop();
		}
		break;

		// siodma operacja umozliwia powrot do menu glownego
		case 7:
		{
			exitA = false;
		}
		break;
		}
	}


}

void MainMenu::displayTree()
{
	bool exitA = true;
	int varA;
	int elemNumber;
	Tree tree;

	cout << "Z ilu elementow ma byc zbudowane drzewo?" << endl;
	cout << "Wprowadz wartosc: ";
	cin >> elemNumber;

	tree.readFile(elemNumber);

	while (exitA)
	{
		cout << "\n               DRZEWO CZERWONO-CZARNE"						<< endl;
		cout << "********************************************************\n"	<< endl;
		cout << "Wybierz operacje: "											<< endl;
		cout << "(1) Wypisz drzewo"												<< endl;
		cout << "(2) Dodaj elementy"											<< endl;
		cout << "(3) Usun elementy"				/* usuwa korzenie */			<< endl;
		cout << "(4) Usun wybrany element"		/* usuwa wybrany element */		<< endl;
		cout << "(5) Wyszukaj element"											<< endl;
		cout << "(6) Wroc do menu glownego\n"									<< endl;

		cout << "Wybrana operacja: ";
		cin >> varA;
		cout << endl;

		switch (varA)
		{
		// pierwsza operacja drukuje elementy listy
		case 1:
		{
			cout << "Drzewo czerwono-czarne:\n";
			tree.printTree("", "", tree.root);
		}
		break;

		// druga operacja umozliwia dodawanie wybranej ilosci losowych elementow
		case 2:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;

			timer.timerStart();		// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					int rnd = rand() % 30000;
					tree.insert(rnd);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie dodane" << endl << endl;
		}
		break;

		// trzecia operacja zajmuje sie usuwaniem podanej liczby korzeni
		case 3:
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz usunac" << endl;
			cin >> tmp;											// uzytkownik podaje liczbe usuwanych wartosci

			timer.timerStart(); 
			if (tmp > 0)
			{
				for (int i = 0; i < tmp; i++)
				{
					tree.removeNode(tree.root);
				}
			}
			timer.timerStop();
			cout << "Elementy zostaly pomyslnie usuniete" << endl << endl;
		}
		break;

		// czwarta operacja umozliwia usuniecie wybranego przez uzytkownika elementu drzewa
		case 4:
		{
			Timer timer;
			int tmp;
			cout << "Jaki element chcesz usunac?" << endl;
			cin >> tmp;

			timer.timerStart();			 // istnieje mozliwosc usuniecia wybranego elementu
			tree.removeNode(tree.findElement(tmp));
			timer.timerStop();
			cout << "Element zostal pomyslnie usuniety" << endl << endl;
		}
		break;

		// piata operacja pozwala wyszukiwac elementy
		case 5:
		{
			Timer timer;
			int tmp;
			cout << "Jaki element chcesz wyszukac?" << endl;
			cin >> tmp;			// uzytkownik podaje wyszukiwany element

			timer.timerStart(); 
			tree.findElement(tmp);
			timer.timerStop();
		}
		break;

		case 6:
		{
			exitA = false;
		}
		break;
		}
	}
}
