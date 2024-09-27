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
    struct node *next;
} Node;

Node *header = NULL;

Node *createnode(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->next = NULL;
    return newnode;
}

Node *insertAtEnd(Node *head, int item)
{
    Node *newnode = createnode(item);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

Node *insertAtBegining(Node *head, int item)
{
    Node *newnode = createnode(item);
    newnode->next = head;
    return newnode;
}

Node *deleteAtBegining(Node *head)
{
    if (head == NULL)
    {
        printf("linked list empty\n");
        return NULL;
    }
    printf("Deleted element = %d\n", head->data);
    return head->next;
}

Node *deleteAtEnd(Node *head)
{
    if (head == NULL)
    {
        printf("linked list empty\n");
        return NULL;
    }
    else if (head->next == NULL)
    {
        printf("Deleted element = %d\n", head->data);
        return NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("Deleted element = %d\n", temp->next->data);
        temp->next = NULL;
        return head;
    }
}

void displayLL(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("LINKED LIST NOT CREATED\n");
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == NULL)
                printf("%d\n", temp->data);
            else
                printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, num;
    while (true)
    {
        printf("MENU\n1. Insert At end\n2. Insert an Begining\n3. Delete at end\n4. Delete at begining\n5. Insert after a value\n6. Insert before a value\n7. Delete after a value\n8. Delete before a value\n9. Delete particuar value\n10. Count number of nodes\n11. Reverse a Linked List\n12. Display\n13. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            header = insertAtEnd(header, num);
            break;
        case 2:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            header = insertAtBegining(header, num);
            break;
        case 3:
            header = deleteAtEnd(header);
            break;
        case 4:
            header = deleteAtBegining(header);
            break;
        case 12:
            displayLL(header);
            break;
        case 13:
            printf("End of program");
            return 0;
        default:
            printf("Invalid input\n");
            break;
        }
    }
    return 0;
}