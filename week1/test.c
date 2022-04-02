#include <stdio.h>
int main()
{
    char bao = 'a';
    int i = !((bao >= 'A' && bao <= 'Z') || (bao >= 'a' && bao <= 'z'));
    printf("%d\n",i);
    return 0;
}