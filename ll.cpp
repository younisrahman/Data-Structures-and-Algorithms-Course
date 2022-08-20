#include <bits/stdc++.h>
//#include<iostream>
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
void insertInHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insertInTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertInHead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAfterPosition(node *&head, int val, int pos)
{
    node *n = new node(val);
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        n->next = temp->next;
        temp->next = n;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL " << endl;
}
void searchByValue(node *head, int val)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << "Value found at position " << count << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << "Value not found" << endl;
}
void length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Length of the linked list is: " << count << endl;
}
int main()
{
    node *head = NULL;
    insertInHead(head, 1);
    insertInHead(head, 2);
    insertInHead(head, 3);
    insertInTail(head, 4);
    insertInTail(head, 5);
    display(head);
    length(head);
    searchByValue(head, 5);
    searchByValue(head, 7);
    insertAfterPosition(head, 6, 3);
    display(head);

    return 0;
}