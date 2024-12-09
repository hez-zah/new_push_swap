#include "../push_swap.h"

void    rrotate(t_stack **a, bool sig, bool a_b)
{
    t_stack	*head;
	t_stack	*led;

	head = *a;
	led = (*a)->next;
	if (!led || !head)
		return ;
	while (led)
	{
		if (!led->next)
		{
			head->next = NULL;
			led->next = *a;
			*a = led;
			break ;
		}
		head = led;
		led = led->next;
	}
    index_sort(*a);
    if (sig && a_b)
        write (1, "rra\n", 4);
    else if (sig && !a_b)
        write (1, "rrb\n", 4);
}

void    double_rrotate(t_stack **a, t_stack **b)
{
    rrotate(a, false, true);
    rrotate(b, false, false);
    write (1, "rrr\n", 4);
}
