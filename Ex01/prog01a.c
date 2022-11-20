#include <stdio.h>

int main()
{
char c;
printf("Input a character: ");
scanf("%c", &c);
printf("ASCII code of '%c' is %d (0x%x).\n", c, c, c);
return 0;
}