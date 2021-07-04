//Finding the intersection node of a linked list
//By creating it from scratch
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

void intersect(Node *&head1,Node *&head2,int pos)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    pos--;
    while(pos--)
    {
        temp1 = temp1->next;
    }
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int length(Node *head)
{
    Node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

int intersectionOfLinkedList(Node *&head1, Node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    Node *ptr1;
    Node *ptr2;
    int d = 0;
    if (l1 > l2)
    {
        ptr1 = head1;
        ptr2 = head2;
        d = l1 - l2;
    }
    else
    {
        ptr1 = head2;
        ptr2 = head1;
        d = l2 - l1;
    }
    while (d)
    {
        /* code */
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);
    intersect(head1,head2,3);
    display(head1);
    display(head2);
    cout<<intersectionOfLinkedList(head1,head2)<<endl;
    return 0;
}