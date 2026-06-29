
#include<stdio.h>
int max(int a[], int n){
int max=a[0];
for(int i=1;i<n;i++)
{
    if(a[i]>max)
        max=a[i];
}
    return max;
}
void sort(int a[], int n, int pos){
    int count[10]={0},b[n];
    int i;
    for(i=0;i<n;i++)
        count[(a[i]/pos)%10]++;
    for(i=1;i<10;i++)
        count[i]=count[i]+count[i-1];
    for(i=n-1;i>=0;i--){
        b[count[(a[i]/pos)%10]-1]=a[i];
        count[(a[i]/pos)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=b[i];
}
void radix(int a[], int n){
    int high=max(a, n);
    for(int pos=1;(high/pos)>0;pos*=10)
        sort(a, n, pos);
 }
void main(){
    printf("enter array size");
    int n, i;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    radix(a, n);
    printf("sorted array");
    for(i=0;i<n;i++)
        printf("%d", a[i]);
}
