I wrote the node.h, node.cpp, AVLTree.h and AVLTree.cpp files. The rest were provided by my instuctor at the time.

This application is an extension of a previous application Binary Search Tree

When Main.cpp runs it creates several AVL Trees and adds data to each. Once all data has been added to the trees 
the tree is traversed using PreOrderTraversal(). When the final tree is traversed, the tree is also printed.

The Rebalance() fucntion makes sure the tree has a proper balance as the application runs. It calls the 
RotateRight() and RotateLeft() functions accordingly as the tree grows and changes using a balanceFactor variable 
to determine which rotation to use. 
