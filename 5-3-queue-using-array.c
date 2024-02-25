/*queue using array*/
#include <stdio.h>
#include<stdlib.h>
#include<process.h>
#define MAXSIZE 5
int q[MAXSIZE], f = -1, r = -1;
int qfull()
{
    if (r >= MAXSIZE - 1)
        return 1;
    else
        return 0;
}
int qempty()
{
    if ((f == -1 && r == -1) || (f == r))
        return 1;
    else
        return 0;
}
void add(int e)
{
    if (qfull())
        printf("\nQueue is Full\n");
    else
    {
        r = r + 1;
        q[r] = e;
    }
}
void del()
{
    int e;
    if (qempty())
        printf("\nQueue is Empty\n");
    else
    {
        f = f + 1;
        e = q[f];
        printf("\nThe Deleted element=%d\n", e);
    }
}
void display()
{
    int i;
    if (qempty())
        printf("\nQueue is Empty\n");
    else
    {
        printf("\nThe elements in the Queue are:\n");
        i = f + 1;
        while (i <= r)
        {
            printf("%4d", q[i]);
            i = i + 1;
        }
    }
}
void main()
{
    int ch, item;
printf("::Queue Implementation Using Array::\n");
printf("******MENU******\n");
    do
    {
        printf("1.Insert an element into Queue\n");
        printf("2.Delete an element from Queue\n");
        printf("3.Display elements in the Queue\n");
        printf("4.Exit\n");
        printf("Enter your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Element to be Pushed:\n");
            scanf("%d", &item);
            add(item);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    } while (ch != 4);
}