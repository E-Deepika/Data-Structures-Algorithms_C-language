#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};
struct node *createnode(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the id no.: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void insertFirst(struct node **head){
    struct node *newnode = createnode();
    if(*head == NULL){
        *head = newnode; 
    }
    else{
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
    return;

}
void insertLast(struct node **tail){
    struct node *newnode = createnode();
        (*tail)->next = newnode;
        newnode->prev = *tail;
        *tail = newnode;
    return;
}

void display(struct node **head){
    struct node *temp = *head;
    while(temp!=NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void main(){
    struct node *head = NULL;
    struct node *tail = NULL;
    insertFirst(&head);
    insertLast(&tail);
    // insertLast(&tail);
    display(&head);
}