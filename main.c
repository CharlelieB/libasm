#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
void *data;
struct s_list *next;
} t_list;


extern int ft_strlen(char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t cout);
extern char* ft_strdup(char* buf);
extern int ft_power_test(int x, unsigned int y);
extern int ft_atoi_base(char *nb, char *base);
extern int my_test();
extern void ft_list_push_front(t_list **begin_list, void *data);
extern int	ft_list_size(t_list *lst);

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

	// ------ ft_write -----

	printf("\n----FT_WRITE ----\n\n");

	{
		char str[] = "Hello world";
		size_t n = ft_write(1, str, 11);
		printf("\n");
		printf("Print \"%s\", nb of byte written: %ld\n", str, n);
	
		printf("\nSimulate write failure - [ASM vs original]\n\n");

		n = ft_write(-1, str, 11);
		int errcode = errno;
		perror("");
		printf("Return value: %ld. Errno code: %d\n", n, errcode);
		n = write(-1, str, 11);
		perror("");
		errcode = errno;
		printf("Return value: %ld. Errno code: %d\n", n, errcode);
	}
	// ------ ft_read -----
	
	// printf("\n----FT_READ ----\n\n");
	// {
	// 	char buf[5];
	// 	ssize_t n = ft_read(1, buf, 3);
	// 	buf[n] = 0;
	// 	printf("Read %ld bytes : %s\n", n, buf);
	// }
	// {
	// 	char buf[5];
	// 	ssize_t n = read(1, buf, 3);
	// 	buf[n] = 0;
	// 	printf("Read %ld bytes : %s\n", n, buf);
	// }

	// ------ ft_stdup -----
	
	printf("\n----FT_STRDUP ----\n\n");
	{
		char *buf = "hello world";
		char *res = ft_strdup(buf);
		printf("Copy of \"%s\". Result : \"%s\"\n", buf, res);
		free(res);
	}
	{
		char *buf = "";
		char *res = ft_strdup(buf);
		printf("Copy of \"%s\". Result : \"%s\"\n", buf, res);
		free(res);
	}

	// ------ ft_power -----
	/*
	printf("\n----FT_POWER-----\n\n");
	{
		int x = 2;
		int y = 2;
		printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
		x = 424;
		y = 0;
		printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
		x = 0;
		y = 1;
		printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
		x = 5;
		y = 2;
		printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
		x = -10;
		y = 2;
		printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
	}
	*/
	printf("\n----FT_ATOI_BASE ----\n\n");
	
	{
		//char *nb = 0;
		//char *base = 0;
		//printf("Number : %s. Base : %s. Result : %d", nb, base, ft_atoi_base(nb, base));
		
		char *nb = "FFFF";
		char *base = "0123456789ABCDEF";
		printf("Number : %s. Base : %s. Result : %d\n", nb, base, ft_atoi_base(nb, base));

		nb = "1110";
		base = "01";
		printf("Number : %s. Base : %s. Result : %d\n", nb, base, ft_atoi_base(nb, base));
		nb = "ff";
		base = "0123456789abcdef";
		printf("Number : %s. Base : %s. Result : %d\n", nb, base, ft_atoi_base(nb, base));
		nb = "42";
		base = "abcdebh";
		printf("Number : %s. Base : %s. Result : %d\n", nb, base, ft_atoi_base(nb, base));
		nb = "42";
		base = "0123456789abcdef";
		printf("Number : %s. Base : %s. Result : %d\n", nb, base, ft_atoi_base(nb, base));
	}

	printf("\n----FT_LIST_PUSH_FRONT ----\n\n");
	{
		t_list *l = NULL, *next;

		char *v = "el1"; 
		ft_list_push_front(&l, v);
		char *v2 = "el2";
		ft_list_push_front(&l, v2);
			// printf("%p\n", v);
			// printf("%p\n", v2);

		t_list *head = l;
		while (l)
		{
			printf("%s\n", (char *)(l->data));
			next = l->next;
			//free(l);
			l = next;
		}
		printf("\n----FT_LIST_SIZE ----\n\n");
		printf("%d\n", ft_list_size(head));

		while (head)
		{
			next = head->next;
			free(head);
			head = next;
		}
	}
	return 0;
}
