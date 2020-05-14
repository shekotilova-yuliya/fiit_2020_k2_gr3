#include "BinTree.h"

Node::Node()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

Node::Node(int key)
{
	this->key = key;
	left = right = parent = nullptr;
}


Node* Node::searchMin(Node* root)
{
	Node* curr = root;
	while (curr->left != nullptr) curr = curr->left;
	return curr;
}

Node* Node::searchNext(Node* curr)
{
	Node* res = NULL;
	if (curr->right != NULL)
	{
		res = searchMin(curr);
		return res;
	}
	res = curr->parent;
	Node* tmp = curr;
	while (res != NULL && tmp == res->right)
	{
		tmp = res;
		res = res->parent;
	}
	return res;
}

Node* Node::searchNode(Node* root, int k)
{
	if (root == nullptr) return 0;
	if (root->key == k) return root;
	if (k < root->key) return searchNode(root->left, k);
	else return searchNode(root->right, k);
}

void Node::insertNode(Node* root, Node* node)
{
	if (root == nullptr)
	{
		root->key = node->key;
		root->left = root->right = root->parent = nullptr;
		return;
	}
	Node* x = root;
	Node* y = x;
	while (x != nullptr)
	{
		y = x;
		if (node->key < x->key) x = x->left;
		else x = x->right;
	}
	if (node->key < y->key)
	{
		y->left = new Node();
		y->left->key = node->key;
		y->left->parent = y;
		y->left->left = nullptr;
		y->left->right = nullptr;
	}
	else
	{
		y->right = new Node();
		y->right->key = node->key;
		y->right->parent = y;
		y->right->left = nullptr;
		y->right->right = nullptr;
	}
}

void Node::removeNode(Node* a)
{
	if (a->left == nullptr && a->right == nullptr)
	{
		if (a->parent != nullptr)
		{
			if (a == a->parent->left) a->parent->left = nullptr;
			else a->parent->right = nullptr;
		}
		else a = nullptr;
	}
	else if (a->left == nullptr && a->right != nullptr ||a->left != nullptr && a->right == nullptr)
	{
		if (a->left == nullptr)
		{
			a->right->parent = a->parent;
			if (a->parent->left == a) a->parent->left = a->right;
			else a->parent->right = a->right;
		}
		else if (a->right == nullptr)
		{
			a->left->parent = a->parent;
			if (a->parent->left == a) a->parent->left = a->left;
			else a->parent->right = a->left;
		}
		a = nullptr;
	}
	else
	{
		Node* y = nullptr;
		y = searchNext(a);
		a->key = y->key;
		removeNode(y); 
	}
}

void Node::print(const Node* root)
{
	if (root != nullptr)
	{
		print(root->left);
		cout << " " << root->key << "	";
		print(root->right);
	}
}