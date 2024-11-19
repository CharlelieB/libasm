#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
void *data;
struct s_list *next;
} t_list;


int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strcmp_nb(const int *s1, const int *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}


void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*el;

	el = malloc(sizeof(t_list));
	if (!el)
		return;
	el->data = data;
	el->next = *begin_list;
	*begin_list = el; 
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
  if (!begin_list || !*begin_list || !cmp) return;

    int swapped;
    t_list *ptr;
    t_list *lptr = NULL;

    do {
        swapped = 0;
        ptr = *begin_list;
        while (ptr->next != lptr) {
            if (cmp(ptr->data, ptr->next->data) > 0) //if ptr->data > ptr->next->data
            {
                void *temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr; // Move lptr to the last sorted element
    } while (swapped);
}

int main()
{
    {
	t_list *l = NULL, *next;
    char *strs[5];
    
    strs[0] = "bee";
    strs[1] = "spider";
    strs[2] = "elephant";
    strs[3] = "tiger";
    strs[4] = "cat";

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
        free(tmp);
		tmp = next;
	}
    }

    //LST INT
    {
	t_list *l = NULL, *next;
    int strs[5];
    
    strs[0] = 5;
    strs[1] = 9;
    strs[2] = -5000;
    strs[3] = 100;
    strs[4] = 42;

	ft_list_push_front(&l, &strs[0]);
	ft_list_push_front(&l, &strs[1]);
	ft_list_push_front(&l, &strs[2]);
	ft_list_push_front(&l, &strs[3]);
	ft_list_push_front(&l, &strs[4]);

    t_list *tmp = l;
    printf("\n[Unsorted list]\n\n");
	while (tmp)
	{
		printf("%d\n", *(int *)(tmp->data));
		next = tmp->next;
		tmp = next;
	}

    ft_list_sort(&l, ft_strcmp_nb);
    tmp = l;
    printf("\n[Sorted list]\n\n");

    while (tmp)
	{
		printf("%d\n", *(int *)(tmp->data));
		next = tmp->next;
        free(tmp);
		tmp = next;
	}
    }
}
