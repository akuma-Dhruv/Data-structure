#include "BinaryTreeClass.h"
using namespace std;
class BSTclass {
	BinaryTree<int>* root;

	public:

	BSTclass() {
		root = NULL;
	}

	~BSTclass() {
		delete root;
	}
	private:

	BinaryTree<int>* insert(int data,BinaryTree<int>* node)
	{
	    if(node==NULL)
        {
            BinaryTree<int>*Newnode= new BinaryTree<int>(data);
            return Newnode;
        }
        if(data>node->data)
            root->right=insert(data,node->right);
            else
            root->left=insert(data,node->left);

            return root;
	}

	bool hasData(int data, BinaryTree<int>* addr) {
		if (addr == NULL) {
			return false;
		}

		if (addr->data == data) {
			return true;
		} else if (data < addr->data) {
			return hasData(data, addr->left);
		} else {
			return hasData(data, addr->right);
		}
	}

	public:
	bool hasData(int data) {
		return hasData(data, root);

	}
	void insert(int data)
	{
	    this->root = insert(data,this->root);

	}
};
