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
	Node *find_element(int keyt);	// wyszukuje wezel
	Node *min_node(Node *p);		// wyszukuje najmniejszy wezel
	Node *next_node(Node *p);		// wyszukuje nastepnik
	void rot_left(Node *A);			// rotacja w lewo
	void rot_right(Node *A);		// rotacja w prawo
	void insert(int keyt);			// wstawia wezel
	void remove_node(Node *X);		// usuwa wezel
	void read_file(int val);		// wczytuje dane
	void printTree(std::string sp, std::string sn, Node *p);	// wypisuje drzewo


};