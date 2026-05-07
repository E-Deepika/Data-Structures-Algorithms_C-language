#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createnode()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertFirst()
{
    struct node *newnode = createnode();
    if (head == NULL)
    {
        head = newnode;
        newnode->prev = head;
        tail = newnode;
        tail->next = head;

        return;
    }
    tail->next = newnode;
    newnode->next = head;
    newnode->prev = tail;
    head = newnode;
}

void insertLast()
{
    struct node *newnode = createnode(); 
    newnode->prev = tail;
    tail->next = newnode;
    newnode->next = head;
    tail = newnode;
    head->prev = tail;
}

void insertPos(int pos){
    printf("\n Now enter the element to insert \n");
    struct node *newnode = createnode();
    struct node *temp = head;
    if(pos == 0){
        insertFirst();
    }
    for(int i = 0; i < pos - 1 && temp->next != NULL; i++){
        temp = temp->next;
    }
    temp->next->prev = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
}

void deleteFirst(){ 
    struct node *del = head;
    head->next->prev = tail;
    head = head->next;
    tail->next = head;
    free(del);
}

void deleteLast(){
    struct node *del = tail;
    tail->prev->next = head;
    head->prev = tail->prev;
    tail = tail->prev;
    free(del);
}

void deletePos(int pos){
    if(pos == 0){
        deleteFirst();
    }
    struct node *temp = head;

    for(int i = 0; i < pos - 1 && temp->next != NULL; i++){
       temp = temp->next;
    }

    if(temp == tail){
        deleteLast();
    }
    struct node *del = temp->next;
    temp->next->next->prev = temp;
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
    printf("Back to Head \n");
}

void main()
{ 
   insertFirst();
   insertLast();
   insertLast();
   insertLast();
   insertLast();
   deleteFirst();
   deletePos(4);
    display();
}