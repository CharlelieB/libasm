#include <stdio.h>

extern int ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);

int main()
{
	printf("----STRLEN----\n\n");
	// ----- strlen
   	{ 
		char str[] = "hello world";
		char str2[] = "";
    	printf("The len of \"%s\" is %d\n", str, ft_strlen(str));
    	printf("The len of \"%s\" is %d\n", str2, ft_strlen(str2));
	}
	printf("\n----STRCPY----\n\n");
	// ------ strcpy
	{
		{
			char dst[10];
			char src[] = "hello";
    		printf("Original: \"%s\"\nCopy: \"%s\"\n", src, ft_strcpy(dst, src));
		}
		{
			char dst[10];
			char src[] = "";
    		printf("Original: \"%s\"\nCopy: \"%s\"\n", src, ft_strcpy(dst, src));

		}
	}	

	return 0;
}
