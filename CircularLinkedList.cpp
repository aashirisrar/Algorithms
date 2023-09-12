#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHeadCircular(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTailCircular(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHeadCircular(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void displayCircular(node *head)
{
    node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void deleteAtHead(node *&head)
{
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;
    head = head->next;

    delete toDelete;
}

void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;
}

int main()
{
    node *head = NULL;

    insertAtTailCircular(head, 1);
    insertAtTailCircular(head, 2);
    insertAtTailCircular(head, 3);
    insertAtTailCircular(head, 4);
    insertAtHeadCircular(head, 5);

    deletion(head, 1);
    displayCircular(head);

    return 0;
}