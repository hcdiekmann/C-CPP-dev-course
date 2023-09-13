#include "BinaryTree.hpp"
#include <algorithm> 
 
using namespace std;

BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::AddNode(int data, int left, int right)
{
    if (root == nullptr) {
        root = new node();
        root->data = data;
    }
    UpdateNode(root, data, left, right);
}

void BinaryTree::UpdateNode(node* Node, int rootdata, int left, int right)
{
    if (Node == nullptr)
		return;
	//if the node exists, add the left & right child
    if (Node->data == rootdata) {
        Node->left = new node();
        Node->left->data = left;
        
		Node->right = new node();
        Node->right->data = right;
        return;
    }
    //recusion to run through whole tree
    UpdateNode(Node->left, rootdata, left, right);
    UpdateNode(Node->right, rootdata, left, right);
}

//algorithm inspired by www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
int BinaryTree::Depth(node* Node)
{
    if (Node != nullptr){
		int lDepth = Depth(Node->left);
		int rDepth = Depth(Node->right);
		return max(lDepth, rDepth) + 1;
	}
	return -1;
}

void BinaryTree::Delete(node* rootNode)
{
    if (rootNode != nullptr) {
		Delete(rootNode->left);
		Delete(rootNode->right);
		delete rootNode;
	}
}
