#include "../push_swap.h"

void    push(t_stack **a, t_stack **b, bool sign)
{
    t_stack *aid_b;

    if (!*b)
        return ;
    aid_b = *b;
    *b = (*b)->next;
    lstadd_front(a, aid_b);
    index_sort(*a);
    index_sort(*b);
    if (sign)
        write(1, "pa\n", 3);
    else
        write(1, "pb\n", 3);
}
