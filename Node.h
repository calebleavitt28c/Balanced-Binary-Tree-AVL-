#ifndef __NODE__
#define __NODE__
#include "Observer.h"

class Node
{
public:
	Node(int value = 0, Node * leftChild = nullptr, Node * rightChild = nullptr);
	~Node() = default;
	bool IsLeaf();
	void UpdateHeight();
	int BalanceFactor();

	int value;
	int height = 0;
	Node* left;
	Node* right;

	Observer observer;	// needed for Unit Testing. Do Not Remove


private:


};
#endif
