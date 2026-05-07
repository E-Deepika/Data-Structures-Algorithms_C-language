#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

struct node *createnode(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertFirst(){
    struct node *newnode = createnode();
    if(head == NULL){
        head = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertLast(){
    struct node *newnode = createnode();
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
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
    head->next->prev = NULL;
    head = head->next;
    free(del);
}

void deletePos(int pos){
    struct node *temp = head;
    for(int i = 0; i < pos - 1 && temp->next != NULL; i++){
       temp = temp->next;
    }
    struct node *del = temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    free(del);
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");

}

void main(){
    insertFirst();

    insertLast();
    insertLast();
    insertLast();
    insertPos(1);
    deleteFirst();
    deletePos(2);
    display();
}