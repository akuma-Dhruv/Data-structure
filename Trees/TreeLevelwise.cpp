#include<iostream>
#include"TreeClass.cpp"
#include<queue>
using namespace std;
void printTree(TreeNode<int>* root)         //recursively
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
TreeNode <int>* takeInputLevelWise()
{
int rooot;
cout<<"Enter Root data "<<endl;
cin>>rooot;
TreeNode<int>* root= new TreeNode<int>(rooot);
queue <TreeNode<int>*> pending;
pending.push(root);
while(pending.size()!=0)
{
	TreeNode<int>* front=pending.front();
	pending.pop();
	cout<<"Enter num of children of "<<front->data<<endl;
	int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* ch = new TreeNode<int>(childData);
			front->child.push_back(ch);
			pending.push(ch);
}

}
return root;
}
int main()
{
	TreeNode<int>* root = takeInputLevelWise();
	print(root);
}
