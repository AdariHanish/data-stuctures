#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    int *p;
    printf("ENTER THE NO OF ELEMENTS OF ARRAY:");
    scanf("%d",&n);
    printf("THE NO OF ELEMENTS IN ARRAY ARE:%d\n",n);
    p=(int*)malloc(n* sizeof (int));
    if(p==NULL)
    {
        printf("MEMORY IS NOT ALLOCATED");
    }
    else
    {
        printf("ENTER THE ELEMENTS OF ARRAY:");
        for(i=0;i<n;i++)
        {
            scanf("%d",p+i);
        }
    }
    printf("THE ELEMENTS OF ARRAY ARE:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(p+i));
    }
    free(p);
}