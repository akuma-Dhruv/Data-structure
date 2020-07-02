 #include<iostream>
 #include"BinaryTreeClass.h"
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

