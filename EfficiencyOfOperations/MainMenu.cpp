/* Klasa MainMenu ma za zadanie wyswietlanie menu glowne programu oraz wywoluje funkcje struktur */

#include <iostream>
#include "MainMenu.h"
#include "Timer.h"
#include "Array.h"

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
		case '1':
			displayArray();
			break;

		case '2':
			displayList();
			break;

		case '3':
			displayHeap();
			break;

		case '4':
			displayTree();
			break;

		case '5':
			exit = false;
			break;
		}
	}
}


void MainMenu::displayArray()
{
	bool exitA = true;
	char varA;
	int elemNumber;
	Array array;

	cout << "Z ilu elementow ma byc zbudowana tablica?"	<< endl;
	cout << "Wprowadz wartosc: ";
	cin >> elemNumber;

	array.readFile(elemNumber);

	while (exitA)
	{
		cout << "\n                       TABLICA"									<< endl;
		cout << "********************************************************\n"	<< endl;
		cout << "Wybierz operacje:"												<< endl;
		cout << "(1) Wypisz tablice"											<< endl;
		cout << "(2) Dodaj elementy z przodu"									<< endl;
		cout << "(3) Dodaj elementy z tylu"										<< endl;
		cout << "(4) Dodaj elementy w losowe miejsce"							<< endl;
		cout << "(5) Usun elementy z przodu"									<< endl;
		cout << "(6) Usun elementy z tylu"										<< endl;
		cout << "(7) Usun elementy z losowego miejsca"							<< endl;
		cout << "(8) Wyszukaj element"											<< endl;
		cout << "(9) Wroc do menu glownego\n"									<< endl;

		cout << "Wybrana operacja: ";
		cin >> varA;
		cout << endl;

		switch (varA)
		{
		case '1':
		{
			cout << "Tablica: ";
			array.printArray();
		}
		break;

		case '2':
		{
			Timer timer;
			int tmp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> tmp;
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
		}
		break;

		case '3':
		{
			Timer timer;
			int temp;
			cout << "Ile elementow chcesz dodac?" << endl;
			cin >> temp;
			timer.timerStart();				// generacja losowych liczb, ich ilosc jest zadana przez uzytkownika
			if (temp > 0)
			{
				for (int i = 0; i < temp; i++)
				{
					int rnd_num = rand() % 30000;
					array.pushBack(rnd_num);
				}
			}
			timer.timerStop();
		}
		break;

		case '4':
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
					array.pushRand(rnd_num, rnd1);
				}
			}
			timer.timerStop();
		}
		break;

		case '5':
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
		}
		break;

		case '6':
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
		}
		break;

		case '7':
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
					array.popRand(rnd);
				}
			}
			timer.timerStop();
		}
		break;

		case '8':
		{
			Timer timer;
			int tmp;
			cout << "Podaj wartosc ktora chcesz wyszukac: " << endl;
			cin >> tmp;
			timer.timerStart();			// uzytkownik podaje wyszukiwana wartosc
			array.search(tmp);
			timer.timerStop();
		}
		break;

		case '9':
		{
			exitA = false;
		}
		break;
		}
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
