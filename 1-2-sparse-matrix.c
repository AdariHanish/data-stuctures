#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
   int a[10][10], m[10][10];
   int i, j, k = 1, r, c, e, count = 0;
   printf("enter the no of rows:\n");
   scanf("%d", &r);
   printf("enter the no of coloumns:\n");
   scanf("%d", &c);
   printf("enter the elements of the array:\n");
   for (i = 0; i < r; i++)
   {
      for (j = 0; j < c; j++)
      {
         scanf("%d", &a[i][j]);
      }
   }
   for (i = 0; i < r; i++)
   {
      for (j = 0; j < c; j++)
      {
         if (a[i][j] == 0)
         {
            count = count + 1;
         }
      }
   }
   if (count > (r * c) / 2)
   {
      printf("the given matrix is a sparsr matrix:");
      m[0][0] = r;
      m[0][1] = c;
      m[0][2] = (r * c) - count;
      for (i = 0; i < r; i++)
      {
         for (j = 0; j < c; j++)
         {
            if (a[i][j] != 0)
            {
               m[k][0] = i;
               m[k][1] = j;
               m[k][2] = a[i][j];
               k++;
            }
         }
      }
      for (i = 0; i < (r * c) - count + 1; i++)
      {
         for (j = 0; j < 3; j++)
         {
            printf("%d", m[i][j]);
            printf("\n");
         }
      }
   }
   else
   {
      printf("the matrix is not a sparse matrix");
   }
}