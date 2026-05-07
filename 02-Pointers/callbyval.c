#include <stdio.h>
void callValue(int *x, int *y);
void main(){
    
    int a=10;
    int b=20;
    callValue(&a,&b);
    printf("in the main function: \n");
    printf("the value of a is %d and value of b is %d\n",a,b);
}
void callValue(int *x, int *y){
    int t=*x;
    *x=*y;
    *y=t;
    printf("in the user defined function: \n");
    printf("the value of a is %d and value of b is %d\n",*x,*y);
}