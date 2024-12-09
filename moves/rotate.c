#include "../push_swap.h"

void    rotate(t_stack **a, bool sig, bool a_b)
{
    t_stack  *aid_a;

    if (!*a)
        return ;
    aid_a = *a;
    *a = (*a)->next;
    aid_a->next = NULL;
    lstadd_back(a, aid_a);
    index_sort(*a);
    if (sig && a_b)
        write (1, "ra\n", 3);
    else if (sig && !a_b)
        write (1, "rb\n", 3);
}

void    double_rotate(t_stack **a, t_stack **b)
{
    rotate(a, false, true);
    rotate(b, false, false);
    write (1, "rr\n", 3);
}
