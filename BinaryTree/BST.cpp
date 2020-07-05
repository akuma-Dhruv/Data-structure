 #include<iostream>
 #include"BinaryTreeClass.h"
 #include<queue>
 using namespace std;
#define N NULL
#define BT BinaryTree<int>
#define L left
#define R right
#define D data

BinaryTree<int>* takeInputLevelWise()				///for input
{
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==N)
      return N;
    BinaryTree<int>* root = new BinaryTree<int> (rootdata);
    queue <BinaryTree<int>*> pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        BinaryTree<int>* front = pending.front();
        pending.pop();
        cout<<"Enter left child of "<<front->D<<endl;
        int LChild;
        cin>>LChild;
        if(LChild!=-1)
        {
            BinaryTree<int>* child=new BinaryTree<int>(LChild);
            front->L=child;
            pending.push(child);
        }
        cout<<"Enter Right child of "<<front->D<<endl;
        int RChild;
        cin>>RChild;
        if(RChild!=-1)
        {
            BinaryTree<int>* child=new BinaryTree<int>(RChild);
            front->R=child;
            pending.push(child);
        }
    }
    return root;
}
void printLevelWise(BT* root)		//to print tree
{
if (root==N)
    return;
queue <BT*>pending;
pending.push(root);
while(!pending.empty())
{
    BT* temp=pending.front();
    cout<<temp->data<<":";
    pending.pop();
    if(temp->L!=N)
    {
        pending.push(temp->L);
        cout<<"L"<<temp->L->data;
    }
    if(temp->R!=N)
    {
        pending.push(temp->R);
        cout<<" R"<<temp->R->data;
    }
    cout<<endl;

}
}

void searchBT(BT* root,int p)
{
    if(root==N)
    {
        cout<<"false"<<endl;
        return;
    }
    if(root->D==p)
    {
        cout<<"True"<<endl;
        return;
    }
    else if(root->D>p)
        searchBT(root->L,p);
    else if(root->D<p)
        searchBT(root->R,p);
    else
        cout<<"false"<<endl;
    return;
}
void printInRange(BT* root,int l,int u)
{

    if(root==N)
        return;
    if((root->D>=l) && (root->D<= u))
        cout<<root->D<<" ";
    if(root->D<u||root->D<l)
        printInRange(root->R,l,u);
    if (root->D>u||root->D>l)
        printInRange(root->L,l,u);
}
int maximum(BT* root)
{
    if(root==N)
        return INT_MIN;
        return(max (root->D,max(maximum(root->L),maximum(root->R))));

}
int minimum(BT* root)
{
    if(root==N)
        return INT_MAX;
        return(min (root->D,min(minimum(root->L),minimum(root->R))));

}
bool isbst(BT* root)
{
    if(root==N)
        return true;
    int l=maximum(root->left);
    int r= minimum(root->right);
    bool result = ((root->D > l) && (root->D <= r) && isbst(root->L) && isbst(root->R));
    return result;
    // but time complexity is poor
}
///4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
///4 2 6 10 3 5 2 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
	BT* root =takeInputLevelWise();
	//int p,u;
	//cout<<"enter range: ";
	//cin>>p>>u;
	//printInRange(root,p,u);
    cout<<isBST(root);
}
