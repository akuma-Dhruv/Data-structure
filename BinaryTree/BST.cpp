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
    ///not working properly
    if(root==N)
        return;
    if((root->D>=l) && (root->D<= u))
        cout<<root->D<<" ";
    if(root->D<u)
        printInRange(root->R,l,u);
    if (root->D>u)
        printInRange(root->L,l,u);

	if(root->D>l)
        printInRange(root->L,l,u);
   if(root->D<l)
        printInRange(root->R,l,u);

}

///4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
	BT* root =takeInputLevelWise();
	int p,u;
	cout<<"enter element for search ";
	cin>>p>>u;
	printInRange(root,p,u);
}
