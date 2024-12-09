#include "../push_swap.h"

t_stack	*lstnew(void *content, int index)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->index = index;
	new->nbr = atoi((const char *)content);
	new->len = 1;
	new->lis = false;
	new->target_node = NULL;
	new->next = NULL;
	return (new);
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		last = lstlast(last);
		last->next = new;
	}
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*creat_stack(char **sp)
{
	t_stack	*list;
	int		i;

	i = -1;
	list = NULL;
	while (sp[++i])
		lstadd_back(&list, lstnew(sp[i], i));
	if (sort_stack(list))
	{
		fr_double(sp);
		fr_stacks(list, NULL);
		exit(0);
	}
	lis(&list);
	fr_double(sp);
	return (list);
}
