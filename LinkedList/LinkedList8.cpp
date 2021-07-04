//TO append last k nodes of a linked list
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

void insertAtLast(Node *&head, int val)
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

int lengthOfLinkedList(Node *head)
{
    Node *temp = head;
    int l = 0;
    while(temp!=NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
Node *kNodeAppend(Node *&head, int k)
{
    Node *newhead;
    Node *newtail;
    Node *temp = head;
    int length = lengthOfLinkedList(head);
    int count = 1;
    k = k % length;
    while (temp->next != NULL)
    {
        if (count == length - k)
        {
            newtail = temp;
        }
        if (count == length - k + 1)
        {
            newhead = temp;
        }
        temp = temp->next;
        count++;
    }
    newtail->next = NULL;
    temp->next = head;
    return newhead;
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
int main()
{
    Node *head = NULL;
    insertAtLast(head, 1);
    insertAtLast(head, 2);
    insertAtLast(head, 3);
    insertAtLast(head, 4);
    insertAtLast(head, 5);
    display(head);
    Node *newhead = kNodeAppend(head, 3);
    display(newhead);
    return 0;
}