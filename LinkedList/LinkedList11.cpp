//Merging of two sorted Linked List
//The Linked List that is given is alredy sorted
//*******************Merging Using Recursive Way*********************//
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

Node *mergeLinkedListUsingRecursion(Node *&head1, Node *&head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *result;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (temp1->data > temp2->data)
    {
        result = temp2;
        result->next = mergeLinkedListUsingRecursion(head1, head2->next);
    }
    else
    {
        result = temp1;
        result->next = mergeLinkedListUsingRecursion(head1->next, head2);
    }
    return result;
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
    Node *newhead = mergeLinkedListUsingRecursion(head1, head2);
    display(newhead);
    return 0;
}