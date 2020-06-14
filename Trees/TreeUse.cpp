#include<iostream>
#include"TreeClass.cpp"
using namespace std;
void print(TreeNode<int>* root)         //recursively
{
	if (root== NULL)
		return;
	cout<<root->data<<":";
	for (int i=0;i<root->child.size();i++)
	{
		cout<<root->child[i]->data<<",";
	}
	cout<<endl;
	for (int i=0;i<root->child.size();i++)
	{
		print(root->child[i]);
	}
}
TreeNode<int>* Takeinput()          //recursively
{
	int data;
	cout<<"Enter data: ";
	cin>>data;
	TreeNode<int>* root = new TreeNode<int>(data);

	int n;
	cout<<"Enter number of child of "<<data<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		TreeNode<int>* d= Takeinput();
		root->child.push_back(d);
	}
	return root;
}
int main()
{


TreeNode<int>* root = Takeinput();
	print(root);
}
