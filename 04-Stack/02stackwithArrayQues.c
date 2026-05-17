#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char data[100];
    struct node *next;
};

struct node *top = NULL;

void push(char data[]){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->data, data);
    newnode->next = top;
    top = newnode;

}

void pop(){
    if(top == NULL){
        printf("Nothing is there to UNDO\n");
        return;
    }
    struct node *del = top;
    top = top->next;
    free(del);
}

void display(){
    if(top == NULL){
        printf("Text Editor is Empty\n");
        return;
    }
    printf("Current Text is: %s\n", top->data);
    
}

void main(){
    char letter[100];
    int status;
    do{
        if(top != NULL){
            display();
        }
        else{
            printf("No data found \n");
        }
        printf("Enter 1 to write the letter\n2 to undo the previous letter\n0 to exit: ");
        scanf("%d", &status);
        switch(status){
            case 1: printf("Enter the Text: ");
                    scanf("%[^\n]", letter);
                    push(letter);
                    break;
            case 2: pop();
                    break;
            case 0: break;
            default: printf("Choose the valid choice\n");
        }
    }
    while(status!=0);

}