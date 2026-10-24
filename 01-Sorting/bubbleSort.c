//bubble sort code

#include <stdio.h>
void main(){
    int n;
    printf("enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements in the array: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("the sorted array is: \n");
    for(int i=0; i<n; i++){
        printf("%d \n", a[i]);
    }
}