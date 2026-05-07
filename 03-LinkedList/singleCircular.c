#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

struct node *createnode()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

void insertFirst()
{
    struct node *newnode = createnode();
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        tail->next = head;
        return;
    }
    newnode->next = head;
    head = newnode;
    tail->next = head;
}

void insertLast()
{
    struct node *newnode = createnode();
    if (head == NULL)
    {
        insertFirst();
    }
    newnode->next = head;
    tail->next = newnode;
    tail = newnode;
}

void insertPos(int pos)
{
    struct node *newnode = createnode();
    struct node *temp = head;
    if(pos == 0){
        insertFirst();
    }
    for (int i = 0; i < pos - 1 && temp->next != head; i++){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteFirst()
{
    struct node *del = head;
    head = head->next;
    tail->next = head;
    free(del);
}

void deleteLast()
{
    struct node *del = tail;
    struct node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = head;
    tail = temp;
    free(del);
}

void delPos(int pos)
{
    if (pos == 0)
    {
        deleteFirst();
    }
    struct node *temp = head;
    for (int i = 0; i < pos - 1 && temp->next != head; i++)
    {

        temp = temp->next;
    }
    struct node *del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

void display()
{
    struct node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD");
}

void main()
{
    insertFirst();
    insertLast();
    insertLast();
    insertLast();
    //    deleteFirst();
    //    deleteLast();
    delPos(2);
    insertPos(2);
    display();
}