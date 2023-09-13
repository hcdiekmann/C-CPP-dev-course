#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main()
{
	BinaryTree* tree = new BinaryTree();
	int n;
	cin >> n;
		
	for(int i=0;i<n;i++)
	{
		int value, left, right;
		cin >> value >> left >> right;
		tree->AddNode(value, left, right);
	}
	
	cout << "depth is " << tree->Depth(tree->root) << endl;
	tree->Delete(tree->root);
	delete tree;
	return 0;
}

 


