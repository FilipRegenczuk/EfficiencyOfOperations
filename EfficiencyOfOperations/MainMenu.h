#pragma once


class MainMenu
{
public:
	void displayMenu();
	MainMenu();
	virtual ~MainMenu();

private:
	bool exit;
	char var;
	void displayArray();
	void displayList();
	void displayHeap();
	void displayTree();

};