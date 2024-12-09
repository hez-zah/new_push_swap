#include "../push_swap.h"

void    swap(t_stack **a, bool sig, bool a_b)
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
    index_sort(*a);
    if (sig && a_b)
        write (1, "sa\n", 3);
    else if (sig && !a_b)
        write (1, "sb\n", 3);
}

void double_swap(t_stack **a, t_stack **b)
{
    swap(a, false, true);
    swap(b, false, false);
    write(1, "ss\n", 3);
}