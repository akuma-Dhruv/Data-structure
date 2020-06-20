 #include<iostream>
 #include"BinaryTreeClass.h"
 using namespace std;
#define N NULL
#define L left
#define R right
#define D data


void print(BinaryTree<int>* root)
{
    if(root==N)
        return;
cout<<root->D<<":";
if (root->L!=N) {
		cout << "L " << root->L->D<<" ";
	}

	if (root->R!=N) {
		cout << "R " << root->R->D;
	}
	cout<<endl;
print(root->L);
print(root->R);

}
int main()
{
BinaryTree<int>* root = new BinaryTree<int>(1);
	BinaryTree<int>* node1 = new BinaryTree<int>(2);
	BinaryTree<int>* node2 = new BinaryTree<int>(3);
	root->left = node1;
	root->right = node2;
	print(root);
}
