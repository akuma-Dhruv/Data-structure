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
void printLevelWise(TreeNode<int>* root)
{
    if(root==NULL)
        return ;
    queue <TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>*temp=q.front();
        q.pop();
        cout<<temp->data<<":";
        for(int i=0;i<temp->child.size();i++)
        {

            q.push(temp->child[i]);
        }
    cout<<endl;
    }

}
/**
vector<int> retarr(TreeNode<int>* root,vector<int>ar)
{int r=root->data;

    for(int i=0;i<root->child.size();i++)
    {
        ar[i]=r;
        retarr(root->child[i],ar);

    }
    return ar;
}
///incomplete********
*@incomplete
///incomplete********
void identical(TreeNode<int>* root1,TreeNode<int>* Root2)
{
    if(root1->child.size()!=Root2->child.size())
        return;

}
*/
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
int height(TreeNode<int>* root)
{
 int max = 0;
    int y=0;
    for( int i=0;i<root->child.size();i++)
    {


            y=height(root->child[i]);
        if (max <y )
            max =y;
    }
    return max + 1;
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
//10 3 20 30 40 2 50 60 0 0 0 0
int main()
{
	TreeNode<int>* root = takeInputLevelWise();
	//cin>>k;
/*	printLevel(root,k);*/
//printLevelWise(root);
//cout<<countLeaf(root);
//postOrder(root);
//checkIf(root,k);

//cout<<height(root);
vector<int> bc;
retarr(root,bc);
for(int i=0;i<bc.size();i++)
cout<<bc.at(i);
delete root;
}
