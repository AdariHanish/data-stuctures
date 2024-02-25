#include<stdio.h>
#include<stdlib.h>
int main()
{
    int key,x,arr[x],mid,low=0,high=x-1;
    printf("Enter the size of array:");
    scanf("%d",&x);
    printf("Enter the elements of array");
    for(int i=0;i<x;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched:");
    scanf("%d",&key);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==mid)
        {
            key==1;
            break;
        }
        else if(arr[key]>mid)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(key==1)
    {
        printf("element found");
    }
    else{
        printf("not found");
    }
    return 0;
}