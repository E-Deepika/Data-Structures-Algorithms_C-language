#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    *head = newNode;
    newNode->next = *head;
}

void insertAtLast(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the LinkedList
void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insertAtFirst(&head, 10);
    insertAtLast(&head, 20);
    print(head);
}

// void main(){
//     int a=10;
//     int *ptr = &a;
//     printf("the adress of value a is %p\n",ptr);
//     ptr++;
//     printf("the adress of value a is %p\n",ptr);

// }