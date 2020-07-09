class Node
{
public:
int data;
Node *next;
Node(int d)
{
    data=d;
    next =NULL;
}

void printLL(Node *head)
{
        Node *temp = head;
		while(temp != NULL)
    {
		std::cout << temp -> data << " ";
		temp = temp -> next;
	}
}
};
