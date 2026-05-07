#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(){
struct node* newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&newnode->data);
newnode->next=NULL;
return newnode;
}
void first(struct node** head){
    struct node* newnode=createnode();
    newnode->next=*head;
    *head=newnode;
}

void last(struct node** head){
    struct node* newnode=createnode();
  if(*head==NULL){
      *head=newnode;
      return;
  }
  struct node* temp=*head;
  while(temp->next!=NULL){
      temp=temp->next;
  }
  temp->next=newnode;
}


void middle(struct node** head,int pos){
    struct node* temp=*head;
    struct node* newnode=createnode();
   if(pos==0){
       first(head);
       return;
   } 
   for(int i=0;i<pos-1 && temp->next!=NULL;i++) {
        temp=temp->next;
   }
   if(temp==NULL){
       printf("positon is out of range");
   }

   newnode->next =temp->next;
   temp->next=newnode;
}


void del_beg(struct node** head){
    struct node* temp=*head;
    if(*head==NULL){
        printf("list is an empty");
        return;
    }
    *head=temp->next;
    free(temp);
    
}


void del_end(struct node** head){
   if (*head==NULL){
     printf("your list is empty");
     return;
    }
    struct node* temp=*head;
   if(temp->next==NULL){
      free(temp);
      temp->next=NULL;
   }
   while(temp->next->next!=NULL){
      temp=temp->next;
   }
   free(temp->next);
   temp->next=NULL;

}


void del_mid(struct node** head,int po){
    
    struct node* temp=*head;
     if(po==0){
        del_beg(head);
     }
     for(int i=0;i<po-1 && temp->next!=NULL; i++ ){
         temp=temp->next;
     }
     if(temp==NULL){
          printf("given pos is out of range ");
     }

     struct node* nextf;
     nextf=temp->next->next;
     free(temp->next);
     temp->next=nextf;

}


void display(struct node** head){
   struct node* temp=*head;
   while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
   }
}


void main(){
    struct node* head=NULL;
    first(&head);
 for(int i=0;i<3;i++){
   last(&head);
 }
 middle(&head,3);
 del_beg(&head);
 del_end(&head);
 del_mid(&head,2);
 display(&head);
 printf("NULL");
}