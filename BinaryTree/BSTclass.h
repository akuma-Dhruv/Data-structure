#include "BinaryTreeClass.h"
using namespace std;
#define N NULL
#define L left
#define R right
#define BT BinaryTree<int>


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

	BinaryTree<int>* removeE(BinaryTree<int>* node,int e)
	{
	    if(node==N)
            return N;

            if(e>node->data)
            {
                node->R=removeE(node->R,e);
            }
            else if(e<node->data)
            {
                node->L=removeE(node->L,e);
            }
            else{

            if(node->data==e && node->L==N && node->R!=N)
            {
               BT* temp= node->right;
               node->R=N;
               delete node;
               return temp;
            }

           else if(node->data==e && node->L!=N && node->R==N)
            {
               BT* temp= node->L;
               node->L=N;
               delete node;
               return temp;
            }
            else if(node->data==e && node->L!=N && node->R!=N)
             {
                 int minimum;
                 BT* temp;
                 temp=node->R;
                 while(temp->L!=N)
                 {
                     temp=temp->L;
                 }
                 minimum=temp->data;
                 node->data=minimum;
                 node->R=removeE(node->R,minimum);
                 return node;
                 }
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
	void removeE(int data)
	{
    this->root= removeE(root,data);
	}
};
