#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

Node *createnode(int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->next = NULL;
    return newnode;
}

void insertAtFirst(int item)
{
    Node *newnode = createnode(item);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }
    newnode->next = head;
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = newnode;
    temp->next = head;
}

void insertAtLast(int item)
{
    Node *newnode = createnode(item);
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        temp->next->next = head;
    }
}

void insertafter(int item, int after)
{
    if (head == NULL)
    {
        printf("LinkedList is empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == after)
        {
            Node *newnode = createnode(item);
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        if(temp->next==head)
        temp=NULL;
        else
        temp = temp->next;
    }
    printf("AFTER element not present\n");
}

void insertbefore(int item, int before)
{
    if (head == NULL)
    {
        printf("LinkedList is empty\n");
        return;
    }

    if (head->data == before)
    {
        Node *newnode = createnode(item);
        newnode->next = head;
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = newnode;
        temp->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == before)
            {
                Node *newnode = createnode(item);
                newnode->next = temp->next;
                temp->next = newnode;
                return;
            }
            temp = temp->next;
        }
        printf("BEFORE element not found");
    }
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("Linked list empty nothing to delete\n");
        return;
    }
    Node *del = head;
    head = head->next;
    Node* temp = head;
    while(temp->next!=del)
    {
        temp=temp->next;
    }
    temp->next=head;
    free(del);
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("Linked list empty nothing to delete\n");
        return;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *del = temp->next;
        temp->next = head;
        free(del);
    }
}


void display()
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("LINKED LIST EMPTY\n");
        return;
    }
    while (temp->next != head)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> head\n", temp->data);
    return;
}

void displayAddress()
{
    if (head == NULL)
    {
        printf("CIRCULAR LINKED LIST IS EMPTY\n");
        return;
    }
    Node *temp = head;
    int i = 1;
    while (temp->next != head)
    {
        printf("node %d\n", i);
        printf("temp = %u\n", temp);
        printf("temp->data = %d\n", temp->data);
        printf("temp->next = %u\n", temp->next);
        printf("\n\n");
        i++;
        temp = temp->next;
    }
    printf("node %d\n", i);
    printf("temp = %u\n", temp);
    printf("temp->data = %d\n", temp->data);
    printf("temp->next = %u\n", temp->next);
    printf("\n\n");
}

void freeList()
{
    Node *temp = head;
    while (temp->next != head)
    {
        Node *del = temp;
        temp = temp->next;
        free(del);
    }
    free(temp);
    head = NULL;
}

int main()
{
    int ch, term, term2;
    printf("MENU\n1. Insert first\n2. Insert last\n3. insert after a particular node\n4. Insert before a particular node\n5. Delete at first\n6. Delete at last\n7. Delete after an element\n8. Delete before an element\n9. Display\n10. Display address\n11. Exit\n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number to be inserted : ");
            scanf("%d", &term);
            insertAtFirst(term);
            break;
        case 2:
            printf("Enter number to be inserted : ");
            scanf("%d", &term);
            insertAtLast(term);
            break;
        case 3:
            printf("Enter number to be inserted : ");
            scanf("%d", &term);
            printf("Enter number after which it need to be inserted : ");
            scanf("%d", &term2);
            insertafter(term, term2);
            break;
        case 4:
            printf("Enter number to be inserted : ");
            scanf("%d", &term);
            printf("Enter number before which it need to be inserted : ");
            scanf("%d", &term2);
            insertbefore(term, term2);
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteLast();
            break;
        // case 7:
        //     printf("Enter value after which it will be deleted : ");
        //     scanf("%d", &term2);
        //     deleteAfter(term2);
        //     break;
        // case 8:
        //     printf("Enter value before which it will be deleted : ");
        //     scanf("%d", &term2);
        //     deleteBefore(term2);
        //     break;
        case 9:
            display();
            break;
        case 10:
            displayAddress();
            break;
        case 11:
            freeList();
            printf("END OF PROGRAM\n");
            return 0;
        default:
            printf("INVALID SELECTION\n");
        }
    }
    return 0;
}