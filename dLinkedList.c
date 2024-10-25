#include <stdio.h>
#include <stdlib.h>

enum boolean
{
    false,
    true
};

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
    if(head==NULL)
    {
        head=newnode;
        return;
    }
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

void insertBefore(int item, int before)
{
    if (head == NULL)
    {
        printf("Linked List empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == before)
        {
            Node *newnode = createnode(item);
            if (temp->prev == NULL)
            {
                newnode->next = temp;
                temp->prev = newnode;
                head = newnode;
                return;
            }
            else
            {
                newnode->next = temp;
                temp->prev->next = newnode;
                newnode->prev = temp->prev;
                temp->prev = newnode;
                return;
            }
        }
        temp=temp->next;
    }
    printf("Before element not found\n");
}

void deleteAtEnd()
{
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    Node* del=temp->next;
    temp->next=NULL;
    free(del);
}

void deleteAtFront()
{
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    Node* del=head;
    head=head->next;
    head->prev=NULL;
    free(del);
}

void deleteAfterAValue(int val)
{
    if(head==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            if(temp->next==NULL)
            {
                printf("no after node present to be deleted\n");
                return;
            }
            else
            {
                Node* del=temp->next;
                temp->next=temp->next->next;
                temp->next->prev=temp;
                free(del);
                return;
            }
        }
        temp=temp->next;
    }
    printf("After node not found\n");
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
    int choice, num, num2;
    while (true)
    {
        printf("MENU\n1. Insert At end\n2. Insert an Begining\n3. Delete at end\n4. Delete at begining\n5. Insert after a value\n6. Insert before a value\n7. Delete after a value\n8. Delete before a value\n9. Delete particular value\n10. Count number of nodes\n11. Reverse a Linked List\n12. Display\n13. Display all details of node\n14. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            insertAtEnd(num);
            break;
        case 2:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            insertAtBegining(num);
            break;
        case 3:
            deleteAtEnd();
            break;
        case 4:
            deleteAtFront();
            break;
        case 5:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            printf("enter the value after which the data need to be inserted : ");
            scanf("%d", &num2);
            insertAfter(num, num2);
            break;
        case 6:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            printf("enter the value before which the data need to be inserted : ");
            scanf("%d", &num2);
            insertBefore(num, num2);
            break;
        case 7:
            printf("Enter a value after which node deletion will be deleted : ");
            scanf("%d", &num2);
            deleteAfterAValue(num2);
            break;
        // case 8:
        //     printf("Enter a value before which node deletion will be deleted : ");
        //     scanf("%d", &num2);
        //     header = deleteBeforeAValue(header, num2);
        //     break;
        // case 9:
        //     printf("Enter value that need to be deleted : ");
        //     scanf("%d", &num2);
        //     header = deleteParticularValue(header, num2);
        //     break;
        case 10:
            printf("No of nodes in linked List is %d\n", countNodes());
            printf("Total size of linked list = %d bytes\n", sizeof(Node) * countNodes());
            break;
        // case 11:
        //     header = reverseLL(header);
        //     if (header == NULL)
        //         printf("Linked List not present\n");
        //     else
        //         displayLL(header);
        //     break;
        case 12:
            display();
            break;
        case 13:
            displayAddress();
            break;
        case 14:
            printf("End of program");
            return 0;
        default:
            printf("Invalid input\n");
            break;
        }
    }
    return 0;
    // printf("No of nodes = %d\n", countNodes());
    // printf("Total size of linked list = %d bytes\n", sizeof(Node) * countNodes());
    // return 0;
}