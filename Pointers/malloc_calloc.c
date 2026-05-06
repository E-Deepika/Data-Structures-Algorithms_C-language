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
    int m;
    float *pt;
    printf("enter the size of numbers: ");
    scanf("%d", &m);
    pt = (float *)malloc(m*sizeof(float));
    printf("enter the float numbers: \n");
    for(int i=0; i<m; i++){
        scanf("%f", (pt + i));
    }
    printf("The entered float values are: \n");
    for(int i=0; i<m; i++){
        printf("%.2f \n", *(pt + i));
    }
    free(pt);
}