#include "../checker.h"

void    swap(t_stack **a)
{
	t_stack	*head;
	t_stack	*led;

	if (!(*a))
		return ;
	head = (*a)->next;
	if (!head)
		return ;
	(*a)->next = NULL;
	led = head->next;
	head->next = NULL;
	head->next = *a;
	(*a)->next = led;
	*a = head;
}

void double_swap(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
}

void    push(t_stack **a, t_stack **b)
{
    t_stack *aid_b;

    if (!*b)
        return ;
    aid_b = *b;
    *b = (*b)->next;
    lstadd_front(a, aid_b);
}

bool    sort_stack(t_stack *list)
{
    if (!list)
        return (true);
    while (list->next)
    {
        if (list->nbr > list->next->nbr)
            return (false);
        list = list->next;
    }
    return (true);
}