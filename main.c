#include <stdio.h>

extern int ft_strlen(char *str);

int main()
{
	// ----- strlen
    
	char str[] = "hello world";
    	printf("The len of \"%s\" is %d\n", str,ft_strlen(str));

	return 0;
}
