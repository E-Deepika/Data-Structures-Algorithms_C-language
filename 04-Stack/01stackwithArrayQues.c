// Browser Back Button (Stack - Array)
// You are building a browser. When a user visits pages, they should be able to go back.
// Task: Implement Visit page and Back functionality using stack.

#include <stdio.h>
#include <string.h>
#define N 5
#define MAX_LEN 100
char stack[N][MAX_LEN];
int top = -1;

void push(char data[]){
    if(top == N-1){
        printf("the stack is Full");
        return;
    }
    strcpy(stack[++top], data);

}
void pop(){
    if(top == -1){
        printf("You are out of page\n");
        return;
    }
    top--;
    
}

void main(){
    int status;
    char str[MAX_LEN];
    do{
        if(top != -1){
            printf("You are currently in %s \n", stack[top]);
        }
        else{
            printf("No page found \n");
        }
        printf("Enter 1 to Visit Page\n 2 to Go Back\n 0 to exit the website: ");
        scanf("%d", &status);
        switch(status){
            case 1: printf("enter the page name: ");
                    scanf(" %[^\n]", str);
                    push(str);
                    break;
            case 2: pop(); break;
            case 0: break;
            default: printf("Invalid Choice \n");
        }
    }
    while(status!=0);
}