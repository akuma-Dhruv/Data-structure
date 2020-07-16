 #include<iostream>
 #include"BinaryTreeClass.h"
 #include<queue>
 using namespace std;
 #define N NULL
#define BT BinaryTree<int>
#define L left
#define R right
#define D data
 BinaryTree<int>* takeInputLevelWise()
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
 int getdept(BinaryTree<int>* root,int e)
{
    if(root==NULL)
    {
     return 0;
    }
    if(root->data==e)
    {
        return 1;
    }
    int re=(getdept(root->left,e)+getdept(root->right,e));
    if(re!=0)
        re++;
    return re;

}
BinaryTree<int>* getparent(BinaryTree<int>* root,int e)
{
    if(root==N)
        return N;
        if(root->L!=N)
        {
            if(root->L->D==e)
                return root;
        }
        else if(root->R!=N)
        {
        if(root->R->D==e)
        {
            return root;
        }
        }

            BT* LO=getparent(root->left,e);
            if(LO!=N)
                return LO;
            BT* RO=getparent(root->right,e);
                if(RO!=N)
                return RO;

            return N;


}
bool iscousin(BT* root,int p,int q)
{
    int pd=getdept(root,p);
    int qd=getdept(root,q);
    BT* pp= getparent(root,p);
    BT* qp= getparent(root,q);
    return ((pd==qd)&&(pp!=qp));
}

///1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 -1 24 -1 26 27 -1 28 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 29 -1 -1 -1 -1 -1 30 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTree<int>*root=takeInputLevelWise();
    //BT* g=getparent(root,30);
    cout<<iscousin(root,30,29);


}
