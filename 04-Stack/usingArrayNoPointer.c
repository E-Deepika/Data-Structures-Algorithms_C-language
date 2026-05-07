#include <stdio.h>
#include <string.h> 
#define size 100
int top1=-1;
int top= -1;
int stack[size];
int stack1[size];
void push(){
    int ele;
    printf("enter the element: ");
    scanf("%d", &ele);
    if(top==size-1){
        printf("stack is full");
    }


    
    else{
        top++;
        stack[top]=ele;

    }
}

void popped(){
    if(top == -1){
        printf("stack is empty");
    }
    else{
        int item;
        item = stack[top];
        top--;
        printf("popped element: %d \n", item);
    }
}

void peek(){
    if(top==-1){
        printf("it is an empty stack");
    }
    else{
        int peek = stack[top];
        printf("top element: %d \n", peek);
    }
}

void shift(){
int i=0;
    while(top >= 0){
        stack1[i] = stack[top];
        top--;
        i++;
    }
    top1=i-1;
}
void display(){
    int i;
    for(i=top1; i>=0; i--){
        printf("%d \n", stack1[i]);
    }
}
 

void main(){
    push();
    push();
    push();
    // peek();
    // popped();
    shift();
    display();
    
}