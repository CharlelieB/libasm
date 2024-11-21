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

extern int ft_atoi_base(char *nb, char *base);
extern void ft_list_push_front(t_list **begin_list, void *data);
extern int	ft_list_size(t_list *lst);
extern void ft_list_sort(t_list **begin_list, int (*cmp)());
extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

int	ft_cmp_nb(const int *s1, const int *s2)
{
	if (s1 && s2)
	{
		return (*s1 - *s2);
	}
	return (0);
}

void del(void *data)
{
	free(data);
}

int main()
{
	// ------ ft_power -----

	// printf("\n----FT_POWER-----\n\n");
	// {
	// 	int x = 2;
	// 	int y = 2;
	// 	printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
	// 	x = 424;
	// 	y = 0;
	// 	printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
	// 	x = 0;
	// 	y = 1;
	// 	printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
	// 	x = 5;
	// 	y = 2;
	// 	printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
	// 	x = -10;
	// 	y = 2;
	// 	printf("%d^%d = %d\n", x, y, ft_power_test(x, y));
	// }

	printf("\n----FT_ATOI_BASE ----\n\n");
	
	{
		char *nb = 0;
		char *base = 0;
		printf("Number : %s. Base : %s. Result : %d\n", nb, base, ft_atoi_base(nb, base));
		
		nb = "FFFF";
		base = "0123456789ABCDEF";
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

	printf("\n----FT_LIST_SORT ----\n\n");

 	{
		t_list *l = NULL, *next;
		char *strs[5];
	
		strs[0] = malloc(sizeof(char) * ft_strlen("bee"));
		ft_strcpy(strs[0], "bee");

		strs[1] = malloc(sizeof(char) * ft_strlen("spider"));
		ft_strcpy(strs[1], "spider");
		
		strs[2] = malloc(sizeof(char) * ft_strlen("elephant"));
		ft_strcpy(strs[2], "elephant");

		strs[3] = malloc(sizeof(char) * ft_strlen("tiger"));
		ft_strcpy(strs[3], "tiger");
		
		strs[4] = malloc(sizeof(char) * ft_strlen("cat"));
		ft_strcpy(strs[4], "cat");

		// strs[0] = "bee";
		// strs[1] = "spider";
		// strs[2] = "elephant";
		// strs[3] = "tiger";
		// strs[4] = "cat";

		ft_list_push_front(&l, strs[0]);
		ft_list_push_front(&l, strs[1]);
		ft_list_push_front(&l, strs[2]);
		ft_list_push_front(&l, strs[3]);
		ft_list_push_front(&l, strs[4]);

		t_list *tmp = l;
		printf("[Unsorted list]\n\n");
		while (tmp)
		{
			printf("%s\n", (char *)(tmp->data));
			next = tmp->next;
			tmp = next;
		}

		ft_list_sort(&l, ft_strcmp);
		tmp = l;
		printf("\n[Sorted list]\n\n");

		while (tmp)
		{
			printf("%s\n", (char *)(tmp->data));
			next = tmp->next;
			tmp = next;
		}
		char* to_del = "bee";
		ft_list_remove_if(&l, to_del, ft_cmp_nb, del);
		to_del = "tiger";
		ft_list_remove_if(&l, to_del, ft_cmp_nb, del);
		to_del = "spider";
		ft_list_remove_if(&l, to_del, ft_cmp_nb, del);
		to_del = "cat";
		ft_list_remove_if(&l, to_del, ft_cmp_nb, del);
		to_del = "elephant";
		ft_list_remove_if(&l, to_del, ft_cmp_nb, del);

		tmp = l;
		while (tmp)
		{
			printf("%s\n", (char *)(tmp->data));
			tmp = tmp->next;
		}
	}

		//LST INT
	{
		t_list *l = NULL, *next;
		int *strs[5];
		
		strs[0] = malloc(sizeof(int));
		*(strs[0]) = 5;

		strs[1] = malloc(sizeof(int));
		*(strs[1]) = 9;
		
		strs[2] = malloc(sizeof(int));
		*(strs[2]) = -5000;
		
		strs[3] = malloc(sizeof(int));
		*(strs[3]) = 100;
		
		strs[4] = malloc(sizeof(int));
		*(strs[4]) = 42;

		ft_list_push_front(&l, strs[0]);
		ft_list_push_front(&l, strs[1]);
		ft_list_push_front(&l, strs[2]);
		ft_list_push_front(&l, strs[3]);
		ft_list_push_front(&l, strs[4]);

		t_list *tmp = l;
		printf("\n[Unsorted list]\n\n");
		while (tmp)
		{
			printf("%d\n", *(int *)(tmp->data));
			next = tmp->next;
			tmp = next;
		}

		ft_list_sort(&l, ft_cmp_nb);
		tmp = l;
		printf("\n[Sorted list]\n\n");

		while (tmp)
		{
			printf("%d\n", *(int *)(tmp->data));
			tmp = tmp->next;
		}
		int to_del = -5000;
		ft_list_remove_if(&l, &to_del, ft_cmp_nb, del);
		to_del = 9;
		ft_list_remove_if(&l, &to_del, ft_cmp_nb, del);
		to_del = 5;
		ft_list_remove_if(&l, &to_del, ft_cmp_nb, del);
		to_del = 100;
		ft_list_remove_if(&l, &to_del, ft_cmp_nb, del);
		to_del = 42;
		ft_list_remove_if(&l, &to_del, ft_cmp_nb, del);

		tmp = l;
		while (tmp)
		{
			printf("%d\n", *(int *)(tmp->data));
			tmp = tmp->next;
		}
	}
	{
		ft_list_push_front(NULL, NULL);
	}
    return 0;
}
