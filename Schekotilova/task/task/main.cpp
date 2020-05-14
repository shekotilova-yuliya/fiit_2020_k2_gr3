#include "BinTree.h"
#include<iostream>
#include <time.h>

using namespace std;

int main()
{
	int n;
	Node tree(50);
	srand(time(0));
	int k;
	cout << "enter a number of keys(from 1 to 50): " << endl;
	cin >>k;
	for (int i = 0; i < k; i++)
	{
		int number = rand() % 100;
		Node node(number);
		Node::insertNode(&tree, &node);
	}
	cout << "tree keys:" << tree << endl;
	cout << "which key is deleted ";
	cin >> n;
	tree.removeNode(Node::searchNode(&tree, n));
	cout << "keys after deleting" << tree << endl;
	system("pause");
	return 0;
}