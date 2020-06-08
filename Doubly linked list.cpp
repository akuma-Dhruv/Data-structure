#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node *prev;
Node(int d)
{
    data=d;
    next =NULL;
	prev= NULL;
}
};
