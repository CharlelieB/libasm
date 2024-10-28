#include <stdio.h>
#include <string.h>

extern int ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

void test_cmp(const char *s1, const char *s2)
{
	printf("[ASM version vs orignal]\n\n");
   	printf("Compare: \"%s\" and : \"%s\" : %d\n", s1, s2, ft_strcmp(s1, s2));
   	printf("Compare: \"%s\" and : \"%s\" : %d\n\n", s1, s2, strcmp(s1, s2));
}

int main()
{
	// ----- strlen -----

	printf("----STRLEN----\n\n");
   	{ 
		char str[] = "hello world";
		char str2[] = "";
    	printf("The len of \"%s\" is %d\n", str, ft_strlen(str));
    	printf("The len of \"%s\" is %d\n", str2, ft_strlen(str2));
	}

	// ------ strcpy -------

	printf("\n----STRCPY----\n\n");
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

	// ------ strcmp -----

	printf("\n----STRCMP----\n\n");
	{
		char *s1 = "hello world";
		char *s2 = "hello world";

		test_cmp(s1, s2);

		s1 = "hello wor";
		s2 = "hello world";
		
		test_cmp(s1, s2);

		s1 = "hello word";
		s2 = "hello world";
		
		test_cmp(s1, s2);

		s1 = "hello world!!";
		s2 = "hello world";
		
		test_cmp(s1, s2);

	}	

	return 0;
}
