#ifndef __BINARRYSEARCHTREE__
#define __BINARYSEARCHTREE__
#include <string>
#include "Node.h"

class AVLTree
{
public:
	AVLTree(); //done
	~AVLTree();;
	Node* DestructorHelper(Node* cursor);

	void Insert(int value); //done
	void PreOrderTraversal(); //done
	Node* GetRoot() { return root; }
	void Print(); //done
	Node* Rebalance(Node* cursor);
	Node* RotateRight(Node* cursor);
	Node* RotateLeft(Node* cursor);

	Node* root;
	Node* tmpNode = nullptr;
	int sizeofTree = 0;

private:
	Node* InsertHelper(Node* cursor, int value); //done
	void PreOrderHelper(Node* cursor);			//done
	void PrintHelper(std::string& offset, Node* cursor); //done

};
#endif

