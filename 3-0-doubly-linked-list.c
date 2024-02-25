#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
struct node
{
    struct node*prev;
    int data;
    struct node *next;
};
struct node *first = NULL, *newnode, *last,*t1,*t;
void main()
{
    int c;
    void create();
    void insert();
    void del();
    void disp();
    do
    {
        printf("1.Creation:\n");
        printf("2.Insert:\n");
        printf("3.Delete:\n");
        printf("4.Display:\n");
        printf("5.Exit:\n");
        printf("Enter your choice:\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            del();
            break;
        case 4:
            disp();
            break;
        case 5:
            exit(0);
        }

    } while (c != 5);
}

void create()
{
    int k, j;
    printf("How Many Node:");
    scanf("%d", &k);
    for (j = 0; j < k; j++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->prev=NULL;
        newnode->next = NULL;
        if (first == NULL)
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->prev=last;
            last = newnode;
        }
    }
}

void disp()
{
    printf("DLL:\n");
    for (struct node*i = first; i != NULL; i = i->next)
    {
        printf("%d ", i->data);
    }
    printf("\n");
}

void insert()
{
    int choice, p, l = 0;
    printf("1.Insert at front node:\n");
    printf("2.Insert at middle node:\n");
    printf("3.Insert at last node:\n");
    printf("4.Exit:\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->prev=NULL;
    newnode->next = NULL;
    switch (choice)
    {
    case 1:
        newnode->next = first;
        first->prev=newnode;
        first = newnode;
        break;
    case 2:
        printf("Enter Position:\n");
        scanf("%d", &p);
        t=t1= first;
        while (l < p)
        {
            t1=t;
            t = t->next;
            l = l + 1;
        }
        newnode->next = t1->next;
        t1->next = newnode;
        newnode->prev=t1;
        t->prev=newnode;
        break;
    case 3:
        last->next = newnode;
        newnode->prev=last;
        last = newnode;
        break;
    }
}

void del()
{
    int choice, p, l = 0;
    printf("1.Delete front node:\n");
    printf("2.Delete middle node:\n");
    printf("3.Delete last node:\n");
    printf("4.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        t = first;
        first = first->next;
        t->next = NULL;
        first->prev=NULL;
        free(t);
        break;
    case 2:/*
        printf("Enter Post:\n");
        scanf("%d", &p);
        while (l < p)
        {
            t1 = t;
            t = t->next;
            l = l + 1;
        }
        t1->next = t->next;
        t->next = NULL;
        free(t);
        break;
        */
    case 3:
        t1 = t = first;
        while (t->next != NULL)
        {
            t1 = t;
            t = t->next;
        }
        last=t1;
        last->next=NULL;
        t->prev = NULL;

        free(t);
        break;
    }
}