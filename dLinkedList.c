#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;

Node *createnode(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertAtBegining(int item)
{
    Node *newnode = createnode(item);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insertAtEnd(int item)
{
    Node *newnode = createnode(item);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertAfter(int item, int after)
{
    if (head == NULL)
    {
        printf("Linked List empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == after)
        {
            Node *newnode = createnode(item);
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            return;
        }
        temp = temp->next;
    }
}

int countNodes()
{
    int c = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void display()
{
    if (head == NULL)
    {
        printf("DOUBLY LINKED LIST IS EMPTY\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf(temp->next != NULL ? "%d <-> " : "%d\n", temp->data);
        temp = temp->next;
    }
}

void displayAddress()
{
    if (head == NULL)
    {
        printf("DOUBLY LINKED LIST IS EMPTY\n");
        return;
    }
    Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        printf("node %d\n", i);
        printf("temp = %u\n", temp);
        printf("temp->data = %d\n", temp->data);
        printf("temp->next = %u\n", temp->next);
        printf("temp->prev = %u\n", temp->prev);
        printf("\n\n");
        i++;
        temp = temp->next;
    }
}

int main()
{
    insertAtBegining(5);
    insertAtBegining(2);
    insertAtBegining(4);
    insertAtBegining(67);
    display();
    insertAtBegining(590);
    insertAtBegining(6);
    insertAtBegining(-1);
    display();
    insertAtEnd(45);
    insertAtEnd(33);
    insertAtEnd(23);
    insertAtEnd(22);
    display();
    displayAddress();
    insertAtBegining(342);
    insertAtBegining(4433);
    insertAtBegining(1);
    insertAtBegining(1167);
    insertAtEnd(3424);
    display();

    printf("No of nodes = %d\n", countNodes());
    printf("Total size of linked list = %d bytes\n", sizeof(Node) * countNodes());
    return 0;
}