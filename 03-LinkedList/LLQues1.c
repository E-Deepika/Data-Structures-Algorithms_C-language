// program to write linked list that contains the data of the indian cricket team players and display the data of the highest and lowest strike rate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char pname[50];
    char state[50];
    int runs;
    int balls;
    struct node *next;
};
struct node *createnode()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the player name, state, runs, balls: ");
    scanf("%s %s %d %d", newnode->pname, newnode->state, &newnode->runs, &newnode->balls);
    newnode->next = NULL;
    return newnode;
}
void insertBegin(struct node **head)
{
    struct node *newnode = createnode();
    newnode->next = *head;
    *head = newnode;
}
void insertLast(struct node **head)
{
    struct node *newnode = createnode();
    struct node *temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;

}
void calculation(struct node **head){
    int max=0, min=0;
    char srname[20], lwname[50];
    float sr;
    struct node *temp = *head;
    while(temp!=NULL){
        sr = ((temp->runs)/(temp->balls))*100;
        if(max<sr){
            max=sr;
            strcpy(srname, temp->pname);
        }
        if(min>sr){
            min=sr;
            strcpy(lwname, temp->pname);
        }
        
        temp = temp->next;
    }
    printf("the highest strike rate is there for the player %s \n",srname);
    printf("the Lowest strike rate is there for the player %s \n",lwname);
}

void main()
{
    struct node *head = NULL;
    insertBegin(&head);
    for (int i = 2; i <= 3; i++)
    {
        insertLast(&head);
    }
    // display(&head);
    calculation(&head);
}