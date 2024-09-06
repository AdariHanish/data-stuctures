#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        int b;
        scanf("%d", &b);
        if(b>2)
        {
            int c=b/2;
            printf("%d\n", (int)ceil(c));
        }
        else
        {
            printf("%d\n", b);
        }
    }
    return 0;
}