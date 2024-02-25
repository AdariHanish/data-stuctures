#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int size;
    printf("Enter size of elements :");
    scanf("%d",&size);
    ptr=(int*)malloc(size*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory not allocated \n");
    }
    else
    {
        printf("memory successfully allocatedusing malloc\n");
        for(int j=0;j<size;j++)
        {
            ptr[j]=j+1;
        }
        printf("Elements of the array are:");
        for(int k=0;k<size;k++)
        {
            printf("%d",ptr[k]);
        }
    }
    return 0;
}