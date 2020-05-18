#pragma once
#include <iostream>
#include"treenode.h"
#include <time.h>

using namespace std;

class BinTree
{
public:
	Node* root;

	Node();
	Node(int);
	~Node() { left = nullptr; right = nullptr; }
	static Node* search(Node*, int);
	Node* searchMin(Node*);
	Node* searchNxt(Node*);	
	static void insertNode(Node*, Node*);
	void deleteNode(Node*);
	static void print(const Node*);
	friend ostream& operator<<(ostream& out, const BinTree& btree)
	{
		if (btree.root != nullptr) BinTree::print(btree.root);
			return out;
	}
};
