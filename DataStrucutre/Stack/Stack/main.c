#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    int i,j,max_and=0,max_or=0,max_xor=0,and,or,xor;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            and = i & j;
            if((and > max_and) && (and < k))
            {
                max_and = and;
            }
            or = i | j;
            if((or > max_or) && (or < k))
            {
                max_or = or;
            }
            xor = i ^ j;
            if((xor > max_xor) && (xor < k))
            {
                max_xor = xor;
            }
        }
    }
    printf("%d\n",max_and);
    printf("%d\n",max_or);
    printf("%d\n",max_xor);

    return 0;
}
