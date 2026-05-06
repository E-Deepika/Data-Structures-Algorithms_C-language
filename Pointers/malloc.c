#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, *ptr;
    printf("enter the no. of values: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("enter the values: ");
    for(int i = 0; i < n; i++){
        scanf("%d", (ptr + i));
    }
    printf("The entered values are: \n");
    for(int i = 0; i < n; i++){
        printf("%d", *(ptr + i));
    }
    free(ptr);
}