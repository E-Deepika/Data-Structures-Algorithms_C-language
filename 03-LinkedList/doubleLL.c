#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createnode(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertFirst(struct node **head, struct node **tail){
    struct node *newnode = createnode();
    if(*head == NULL){
        *head=newnode;
        *tail=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;

    }
}

void insertEnd(struct node **head, struct node **tail){
    struct node *newnode = createnode();
    if(*head == NULL){
        *head = newnode;
        *tail = newnode;
        return;
    }
     (*tail)->next = newnode;
     newnode->prev = *tail;
     *tail = newnode;

    
}

void insert(struct node **head,struct node **tail, int pos){
    struct node *newnode = createnode();
    if(pos == 0){
        insertFirst(head, tail);
        return;
    }
    
    struct node *temp = *head;
    for(int  i=0; i< pos-1 && temp!=NULL; i++ ){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Out of Range... \n");
        return;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->next->prev= newnode;
    

}

void delete(struct node **head, int pos){
    if(*head==NULL){
        printf("The list is empty");
        return;
    }
    struct node *temp = *head;
    if(pos==0){
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    for(int i=0;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    struct node *del=temp->next;
    temp->next->next->prev=temp;
    temp->next=temp->next->next;
    free(del);

}

void display(struct node **head){
    struct node *temp = *head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void main(){
    struct node *head = NULL;
    struct node *tail = NULL;
    int n=3; 
    for(int i=0;i<n;i++){
        insertEnd(&head, &tail);
    }
    insert(&head, &tail, 2);
    delete(&head,2);
    display(&head);

}
