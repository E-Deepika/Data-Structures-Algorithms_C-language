#include <stdio.h>
#include <stdlib.h>

void main(){
    int *ptr, n;
    printf("enter the no. of blocks: ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    printf("enter the values: \n");
    for(int i=0; i<n; i++){
        scanf("%d", (ptr + i));
    }
    printf("the entered values are: \n");
    for(int i=0; i<n; i++){
        printf("%d \n", *(ptr + i));
    }
    free(ptr);
}