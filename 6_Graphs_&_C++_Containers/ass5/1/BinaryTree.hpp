using namespace std;

class node 
{
public:
    int data;
    node* left = nullptr;
    node* right = nullptr;
};

class BinaryTree
{
public:
	BinaryTree();
    node* root;
	void AddNode(int data, int left, int right);
    void UpdateNode(node* Node, int rootdata, int left, int right);
    int Depth(node* Node);
    void Delete(node* rootNode);
};
    
