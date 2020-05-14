#pragma once
#include <iostream>
#include <time.h>

using namespace std;

struct Node
{
	int key;
	Node* left, *right, *parent;

	Node();
	Node(int); 
	~Node() {left = nullptr;right = nullptr;}

	Node* searchMin(Node*);
	Node* searchNext(Node*);
	static Node* searchNode(Node*, int);
	static void insertNode(Node*, Node*);
	void removeNode(Node*);
	static void print(const Node*);
	friend ostream& operator<<(ostream& out, const Node& root)
	{
		if (&root != nullptr) Node::print(&root);
		return out;
	}
};