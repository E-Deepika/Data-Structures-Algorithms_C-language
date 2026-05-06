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
        for(int j=i+1; j<n-1; j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("the sorted array is: \n");
    for(int i=0; i<n ;i++){
        printf("%d \n", a[i]);
    }
}