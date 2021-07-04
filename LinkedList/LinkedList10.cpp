//Merging of two sorted Linked List
//The Linked List that is given is alredy sorted
//*******************Merging Using Iterative Way*********************//
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *mergeSortedLinkedList(Node *&head1, Node *&head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *dummyNode = new Node(-1);
    Node *ptr3 = dummyNode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data > ptr2->data)
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        else
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummyNode->next;
}
int main()
{
    Node *head1 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 3);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    Node *head2 = NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 4);
    insertAtTail(head2, 6);
    insertAtTail(head2, 8);
    display(head1);
    display(head2);
    Node *newhead = mergeSortedLinkedList(head1, head2);
    display(newhead);
    return 0;
}