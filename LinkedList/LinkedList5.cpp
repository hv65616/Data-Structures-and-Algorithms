//One of the most important topic in linked list
//Based on Floyds Algorithm or Hare and Tortoise Algorithm
//How to create a cycle in the linked list and how to detect a cycle 
//Along with that we delete the cycle in out linked list
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

void insertCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *start;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            start = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = start;
}

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    insertCycle(head, 2);
    cout << detectCycle(head) << endl;

    return 0;
}