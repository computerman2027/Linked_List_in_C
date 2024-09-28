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

Node *insertAfterAValue(Node *head, int val, int item)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return NULL;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            Node *newnode = createnode(item);
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    }
    printf("Value Not found. Insertion not possible\n");
    return head;
}

Node *insertBeforeAValue(Node *head, int val, int item)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return NULL;
    }
    Node *newnode = createnode(item);
    if (head->data == val)
    {
        newnode->next = head;
        return newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == val)
            {
                newnode->next = temp->next;
                temp->next = newnode;
                return head;
            }
        }
    }
    printf("Value Not found. Insertion not possible\n");
    return head;
}

Node *deleteBeforeAValue(Node *head, int val)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return NULL;
    }
    if (head->next->data == val)
    {
        return head->next;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->next->data == val)
        {
            temp->next = temp->next->next;
            return head;
        }
    }
    printf("Value Not found. Deletion not possible\n");
    return head;
}

Node *deleteAfterAValue(Node *head, int val)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return NULL;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            if (temp->next != NULL)
            {
                temp->next = temp->next->next;
            }
        }
        return head;
    }
    printf("Value Not found. Deletion not possible\n");
    return head;
}

Node *deleteParticularValue(Node *head, int val)
{
    if (head->data == val)
        return head->next;
    else
    {
        Node *temp = head;
        while (temp->next->data == val)
        {
            temp->next = temp->next->next;
            return head;
        }
        printf("Value do not exists. Node cannot be deleted\n");
        return head;
    }
}

int countNodes(Node *head)
{
    Node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
    }
    return c;
}

Node *reverseLL(Node *head)
{
    Node *ptr = head;
    Node *pptr = NULL;
    while (ptr != NULL)
    {
        Node *temp = ptr->next;
        ptr->next = pptr;
        pptr = ptr;
        ptr = temp;
    }
    return pptr;
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
    int choice, num, num2;
    while (true)
    {
        printf("MENU\n1. Insert At end\n2. Insert an Begining\n3. Delete at end\n4. Delete at begining\n5. Insert after a value\n6. Insert before a value\n7. Delete after a value\n8. Delete before a value\n9. Delete particular value\n10. Count number of nodes\n11. Reverse a Linked List\n12. Display\n13. Exit\n");
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
        case 5:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            printf("enter the value after which the data need to be inserted : ");
            scanf("%d", &num2);
            header = insertAfterAValue(header, num2, num);
            break;
        case 6:
            printf("enter the data that need to be inserted : ");
            scanf("%d", &num);
            printf("enter the value before which the data need to be inserted : ");
            scanf("%d", &num2);
            header = insertBeforeAValue(header, num2, num);
            break;
        case 7:
            printf("Enter a value after which node deletion will be deleted : ");
            scanf("%d", &num2);
            header = deleteAfterAValue(header, num2);
            break;
        case 8:
            printf("Enter a value before which node deletion will be deleted : ");
            scanf("%d", &num2);
            header = deleteBeforeAValue(header, num2);
            break;
        case 9:
            printf("Enter value that need to be deleted : ");
            scanf("%d", &num2);
            header = deleteParticularValue(header, num2);
            break;
        case 10:
            printf("No of nodes in linked List is %d\n", countNodes(header));
            break;
        case 11:
            header = reverseLL(header);
            if (header == NULL)
                printf("Linked List not present\n");
            else
                displayLL(header);
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