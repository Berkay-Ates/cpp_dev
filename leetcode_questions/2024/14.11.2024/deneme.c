#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x = 5;
    int y = 6;
    printf("%d, %d, %d, %d", ++x, x + y++, x--, y);
    return 0;
}
