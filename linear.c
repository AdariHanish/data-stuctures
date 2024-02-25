#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n,arr[n],k;
    printf("enter the size of array:");
    scanf("%d",&n);
    printf("enter %d values:",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched:");
    scanf("%d",&k);
    for(int i=0;i<arr[n];i++)
    if(k==arr[i])
    {
        printf("the element is found");
    }
    else
    {
        printf("element is not found");
    }
    return 0;
}