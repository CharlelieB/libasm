#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
void *data;
struct s_list *next;
} t_list;


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list *next;

	tmp = begin_list;

	while (tmp)
	{
		if (cmp(tmp->data, data_ref > 0))
		{
            free_fct(tmp->data);
            next = tmp->next;
            free(tmp);
            tmp = next;
		}
		else
            tmp = tmp->next;
	}
}