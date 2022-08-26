#include <bits/stdc++.h>
//#include<iostream>
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
void insertInHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
void insertInEnd(Node *&head, int val)
{
    Node *n = new Node(val);
    Node *temp = head;
    if (head == NULL)
    {
        insertInHead(head, val);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAfterValue(Node *&head, int val, int place)
{
    Node *n = new Node(val);
    Node *temp = head;
    while (temp->next != NULL && place != temp->data)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}
void insertAfterPosition(Node *&head, int val, int place)
{
    Node *n = new Node(val);
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL && place != count)
    {
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next = n;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}
void deleteHead(Node *&head)
{
    Node *toDelete = head;
    head = head->next;
    delete toDelete;
}
void deleteTail(Node *&head)
{

    Node *temp = head;
    int count = 0;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next->next;
    temp->next = NULL;
    delete toDelete;
}
void deleteValue(Node *&head, int val)
{
    Node *temp = head;
    while (temp != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
void length(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << "Length of Linked List is " << count << endl;
}
void search(Node *&head, int val)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << " The Value found in " << count << " location" << endl;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << "Not found" << endl;
}

int main()
{
    Node *head = NULL;
    insertInHead(head, 3);
    insertInHead(head, 5);
    insertInEnd(head, 6);
    insertAfterValue(head, 7, 3);
    insertAfterValue(head, 1, 7);
    insertAfterPosition(head, 8, 2);

    display(head);
    length(head);
    search(head, 6);

    deleteHead(head);
    deleteValue(head, 8);
    deleteValue(head, 1);
    deleteTail(head);
    display(head);
    length(head);
    return 0;
}