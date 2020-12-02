#include "Node.h"

Node::Node(int value, Node* leftChild, Node* rightChild)
{
	this->value = value;
	this->left = leftChild;
	this->right = rightChild;
}

bool Node::IsLeaf()
{
	if (left == nullptr and right == nullptr)
		return true;
	else
		return false;
}

void Node::UpdateHeight()
{
	if (IsLeaf())
	{
		height = 0;
		return;
	}

	int leftN = 0;
	int rightN = 0;


	if (left != nullptr)
	{
		leftN = left->height;
	}
	else
		leftN = -1;

	if (right != nullptr)
	{
		rightN = right->height;
	}
	else
		rightN = -1;

	if (leftN < rightN)
	{
		height = rightN + 1;
		return;
	}
	else
	{
		height = leftN + 1;
		return;
	}
}

int Node::BalanceFactor()
{
	int balanceF = 0;
	int leftHeight = 0;
	int rightHeight = 0; 

	if (left == nullptr)
	{
		leftHeight = -1;
	}
	else
	{
		leftHeight = left->height;
	}

	if (right == nullptr)
	{
		rightHeight = -1;
	}
	else
	{
		rightHeight = right->height;
	}

	balanceF = leftHeight - rightHeight; 

	return balanceF;
}
