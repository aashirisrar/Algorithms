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

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *head, int val)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

void deleteAtHead(node *&head)
{
    node *temp = head;

    head = head->next;

    delete temp;
}

void deleteNode(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

void makeCycle(node *head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 0;

    while (temp->next != NULL)
    {
        if (pos == count)
        {
            startNode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

bool detectCycle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return 1;
    }

    return 0;
}

void intersect(node *head1, node *head2, int pos)
{
    node *temp1 = head1;

    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }

    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    // deleteAtHead(head);
    // deleteNode(head, 1);
    display(head);
    // makeCycle(head, 3);
    // display(head);
    // cout << detectCycle(head);
    // cout << search(head, 6);

    node *head2 = NULL;
    insertAtTail(head2, 1);
    insertAtTail(head2, 2);
    intersect(head, head2, 3);
    display(head2);

    return 0;
}
