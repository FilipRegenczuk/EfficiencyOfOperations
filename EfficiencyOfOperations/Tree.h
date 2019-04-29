#pragma once
#include <string>



struct Node {
	Node *up;
	Node *left;
	Node *right;
	int key;
	char color;
};

class Tree {
public:
	Node Guard;             // wezel straznika
	Node * root;			// korzen

	Tree();
	~Tree();

	void remove(Node *p);			// usuwa cale drzewo
	Node *findElement(int keyt);	// wyszukuje wezel
	Node *minNode(Node *p);		// wyszukuje najmniejszy wezel
	Node *nextNode(Node *p);		// wyszukuje nastepnik
	void rotLeft(Node *A);			// rotacja w lewo
	void rotRight(Node *A);		// rotacja w prawo
	void insert(int keyt);			// wstawia wezel
	void removeNode(Node *X);		// usuwa wezel
	void readFile(int val);		// wczytuje dane
	void printTree(std::string sp, std::string sn, Node *p);	// wypisuje drzewo


};