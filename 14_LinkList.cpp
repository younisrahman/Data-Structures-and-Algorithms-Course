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

int main()
{
    Node *head = NULL;
    insertInHead(head, 3);
    insertInHead(head, 5);
    display(head);
    return 0;
}