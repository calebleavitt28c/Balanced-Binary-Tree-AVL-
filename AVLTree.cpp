#include <iostream>
#include <assert.h>
#include "AVLTree.h"
#include "Node.h"
using namespace std;

AVLTree::AVLTree()
{
	root = nullptr;
}

AVLTree::~AVLTree()
{
	Node* cursor = root;
	DestructorHelper(cursor);
}

Node* AVLTree::DestructorHelper(Node* cursor)
{
	if (cursor == nullptr)
	{
		return nullptr;
	}

	if (cursor->IsLeaf())
	{
		delete cursor;
		return nullptr;
	}
	else
	{
		cursor->left = DestructorHelper(cursor->left);
		cursor->right = DestructorHelper(cursor->right);
		delete cursor;
		return nullptr;
	}
}


void AVLTree::Insert(int value)
{
	root = InsertHelper(root, value);
}

Node* AVLTree::InsertHelper(Node* cursor, int value)
{
	//base case
	if (cursor == nullptr)
		return new Node(value);

	//recursive cases
	if (value < cursor->value)
	{
		cursor->left = InsertHelper(cursor->left, value);
	}

	else
	{
		cursor->right = InsertHelper(cursor->right, value);
	}

	cursor->UpdateHeight();
	cursor = Rebalance(cursor);
	return cursor;
}



// for inversetracersal its similar to print
void AVLTree::PreOrderTraversal()
{
	Node* cursor = root;
	PreOrderHelper(cursor);
	cout << endl;
}

void AVLTree::PreOrderHelper(Node* cursor)
{
	//base case
	if (cursor == nullptr)
		return;
	cout << cursor->value << ", ";
	PreOrderHelper(cursor->left);
	PreOrderHelper(cursor->right);
}

// when printing the height of each node don't use recursion just take it from the node
void AVLTree::Print()
{
	std::string offset = "";
	Node* cursor = root;
	PrintHelper(offset, cursor);
}


void AVLTree::PrintHelper(std::string& offset, Node* cursor)
{
	//base case
	if (cursor == nullptr)
	{
		cout << offset << "[Empty]" << endl;
		return;
	}

	//print node
	if (cursor != nullptr)
	{
		if (cursor->IsLeaf())
		{
			cout << offset << cursor->value << " (" << cursor->height << ")" << " " << "[leaf]" << endl;
			return;
		}
		else
		{
			cout << offset << cursor->value << " (" << cursor->height << ")" << " " << endl;
		}

		string tmp = offset + "   ";
		//check leftChild
		PrintHelper(tmp, cursor->left);
		//check rightChild
		PrintHelper(tmp, cursor->right);
	}

}

Node* AVLTree::RotateRight(Node* cursor)
{
	Node* tmp = nullptr;
	assert(cursor != nullptr);
	tmp = cursor->left;
	assert(tmp != nullptr);
	cursor->left = tmp->right;
	tmp->right = cursor;
	cursor->UpdateHeight();
	tmp->UpdateHeight();
	return tmp;
}

Node* AVLTree::RotateLeft(Node* cursor)
{
	Node* tmp = nullptr;
	assert(cursor != nullptr); //if this is false this will crash the program. Because this is bad
	tmp = cursor->right;
	assert(tmp != nullptr);
	cursor->right = tmp->left;	//if the leftChild of the new root has a left node we use this line of code
	tmp->left = cursor;
	cursor->UpdateHeight();	//because techniqually cursor is still pointing to the old root which is now a child of the new root you start here to update it all properly
	tmp->UpdateHeight();	// now we update the new roots height
	return tmp; // then you where ever this function was called can now be equal to what we are returning which needs to be root
}

Node* AVLTree::Rebalance(Node* cursor)
{
	int balanceFactor = cursor->BalanceFactor();

	if (balanceFactor > 1)
	{
		if (cursor->left->BalanceFactor() < 0)
		{
			cursor->left = RotateLeft(cursor->left);
			cursor = RotateRight(cursor);
		}
		else
		{
			cursor = RotateRight(cursor);
		}
	}

	if (balanceFactor < -1)
	{
		if (cursor->right->BalanceFactor() > 0)
		{
			cursor->right = RotateRight(cursor->right);
			cursor = RotateLeft(cursor);
		}
		else
		{
			cursor = RotateLeft(cursor);
		}
	}

	return cursor;
}

