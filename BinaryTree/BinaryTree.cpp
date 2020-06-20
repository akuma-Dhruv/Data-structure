 #include<iostream>
 #include"BinaryTreeClass.h"
 using namespace std;
#define N NULL
void print(BinaryTree<int>* root)
{
    if(root==N)
        return;
    cout<<root->data<<endl;
print(root->left);
print(root->right);

}
void main()
{

}
