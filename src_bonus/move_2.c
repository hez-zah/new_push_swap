#include "../checker.h"

void    rotate(t_stack **a)
{
    t_stack  *aid_a;

    if (!*a)
        return ;
    aid_a = *a;
    *a = (*a)->next;
    aid_a->next = NULL;
    lstadd_back(a, aid_a);
}

void    double_rotate(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
}

void    rrotate(t_stack **a)
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
}

void    double_rrotate(t_stack **a, t_stack **b)
{
    rrotate(a);
    rrotate(b);
}
