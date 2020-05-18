#pragma once
#include <iostream>

using namespace std;

template <class TData>
class treeNode
{
	int key;
	treeNode *left, *right, *parent;

	treeNode();
	treeNode(int key_);
	treeNode(const treeNode& node);
	~treeNode() { left = nullptr; right = nullptr; }

	treeNode* getL() const;
	treeNode* getR() const;
	treeNode* getPrnt() const;

	void setL(treeNode*);
	void setR(treeNode*);
	void setPrnt(treeNode*);

	friend ostream& operator<<(ostream& out, const treeNode& root)
	{
		out << " " << root.key << "	";
		return out;
	}
};

template <class TData>
treeNode<TData>::treeNode()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class TData>
treeNode<TData>::treeNode(int key)
{
	this->key = key;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template <class TData>
treeNode<TData>::treeNode(const treeNode& n)
{
	key = n.key;
	left = n.left;
	right = n.right;
	parent = n.parent;
}

template <class TData>
treeNode<TData>* treeNode<TData>::getR() const
{
	return right;
}

template <class TData>
treeNode<TData>* treeNode<TData>::getPrnt() const
{
	return parent;
}

template <class TData>
void treeNode<TData>::setL(treeNode* left)
{
	this->left = left;
}

template <class TData>
void treeNode<TData>::setR(treeNode* right)
{
	this->right = right;
}

template <class TData>
void treeNode<TData>::setPrnt(treeNode* parent)
{
	this->parent = parent;
}