#include<iostream>
#include"TreeClass.cpp"
#include<queue>
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
int countNode(TreeNode<int>* root)
{ if (root==NULL)
    return 0;
	int count =1;
	for (int i=0;i<root->child.size();i++)
	{
		count+=countNode(root->child[i]);
	}
	return count;
}

int sumNode(TreeNode<int>* root)
{       if (root==NULL)
    return 0;
	int count =root->data;
	for (int i=0;i<root->child.size();i++)
	{
		count+=sumNode(root->child[i]);
	}
	return count;
}
int getMax(TreeNode<int>* root,int Max=0)
{       if (root==NULL)
    return 0;
	int count =root->data;
	for (int i=0;i<root->child.size();i++)
	{
	if(Max<count)
        Max=count;
		count=getMax(root->child[i],Max);
	}
	if(count>Max)
	return count;
	return Max;
}

void printLevel(TreeNode<int>* root,int k)
{   if (root==NULL)
    return;
    if(k==0)
        cout<<root->data <<" ";
    for(int i=0;i<root->child.size();i++)
    {
        printLevel(root->child[i],k-1);
    }

}
int checkIf(TreeNode<int>* root,int l)
{ int num=root->data;
        if(l==num)
            {
                cout<<"True";
                return 0;
            }

    for (int i=0;i<root->child.size();i++)
	{
        num=checkIf(root->child[i],l);
        if (num==0)
            break;
	}
	return num;
}

TreeNode <int>* takeInputLevelWise()
{
int rooot;
cout<<"Enter Root data "<<endl;
cin>>rooot;
if(rooot==NULL)
    return 0;
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
			cout << "Enter " << i+1 << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* ch = new TreeNode<int>(childData);
			front->child.push_back(ch);
			pending.push(ch);
}

}
return root;
}
int countLeaf(TreeNode<int>* root)
{
    if (root==NULL)
    return 0;
    int count=0;
    if(root->child.size()==0)
        return 1;
        for(int i=0;i<root->child.size();i++)
    {
        count+=countLeaf(root->child[i]);
    }
    return count;
}
void postOrder(TreeNode <int>* root)
{
    for(int i=0;i<root->child.size();i++)
    {
        postOrder(root->child[i]);
    }
    cout<<root->data<<" ";
}
//10 3 20 30 40 2 40 50 0 0 0 0
int main()
{
	TreeNode<int>* root = takeInputLevelWise();
	int k=0;
	cin>>k;
/*	printLevel(root,k);*/
//cout<<countLeaf(root);
//postOrder(root);
checkIf(root,k);
delete root;
}
