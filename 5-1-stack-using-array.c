/*stack using array*/
#define MAXSIZE 10
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int a[MAXSIZE],top=-1;
void main()
{
int ch, e;
void push();
int pop();
void peek();
int isfull();
int isempty();
printf("::Stack Using Array::\n");
printf("******MENU******\n");
do
{
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.PEEK\n");
printf("4.EXIT\n");
printf("ENTER YOUR CHOICE:");
scanf("%d", &ch);
switch(ch)
{
case 1:
if(isfull())
printf("STACK FULL\n");
else
{
printf("\nEnter Element to be pushed:\n");
scanf("%d",&e);
push(e);
}
break;
case 2:
if(isempty())
printf("\nSTACK EMPTY\n");
else
{
printf("\nThe Poped Element=%d",pop());
}
break;
case 3:
if(isempty())
printf("\nSTACK IS EMPTY\n");
else
peek();
break;
case 4:
exit(0);
}
}while(ch!=4);
}
void push(int x)
{
top=top+1;
a[top]=x;
}
int pop()
{
return(a[top--]);
}
void peek()
{
int j;
for(j=top;j>=0;j--)
printf("%4d\n",a[j]);
}
int isfull()
{
if(top==MAXSIZE-1)
return 1;
else
return 0;
}
int isempty()
{
if(top==-1)
return 1;
else
return 0; }