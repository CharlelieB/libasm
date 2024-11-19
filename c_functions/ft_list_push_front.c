#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
void *data;
struct s_list *next;
} t_list;

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*el;

	el = malloc(sizeof(t_list));
	if (!el)
		return; //?set errno in asm
	el->data = data;
	el->next = *begin_list;
	*begin_list = el; 
}

int main()
{
	t_list *l = NULL, *next;

	char *v = "el1"; 
	ft_list_push_front(&l, v);
	char *v2 = "el2";
	ft_list_push_front(&l, v2);

		printf("%p\n", v);
			printf("%p\n", v2);

	while (l)
	{
		printf("%p\n", (char *)(l->data));
		next = l->next;
		free(l);
		l = next;
	}

}
