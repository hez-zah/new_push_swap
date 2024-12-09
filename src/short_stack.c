#include "../push_swap.h"

void    three_stack(t_stack **list)
{
    if ((*list)->nbr == highest_stack((*list)))
        rotate(list, true, true);
    else if ((*list)->next->nbr == highest_stack((*list)))
        rrotate(list, true, true);
    if ((*list)->nbr > (*list)->next->nbr)
        swap(list, true, true);
}

static void    four_stack(t_stack **a, t_stack **b)
{
    t_stack *aid_a;
    long    indx;

    aid_a = *a;
    indx = 0;
    while (aid_a)
    {
        if (aid_a->nbr == smaller_stack(*a))
            indx = aid_a->index;
        aid_a = aid_a->next;
    }
    while (indx && indx < 3)
    {
        rotate(a, true, true);
        indx--;
    }
    if (indx == 3)
        rrotate(a, true, true);
    push(b, a, false);
    three_stack(a);
    push(a, b, true);
}

static void    five_stack(t_stack **a, t_stack **b)
{
    t_stack *aid_a;
    t_stack *smaller;
    int     j;

    j = 3;
    while (--j)
    {
        aid_a = *a;
        set_abov_medlan(aid_a);
        smaller = small_node(aid_a);
        if (smaller->abov_medlan)
            while (smaller != *a)
                rotate(a, true, true);
        else
            while (smaller != *a)
                rrotate(a, true, true);
        push(b, a, false);
    }
    three_stack(a);
    push(a, b, true);
    push(a, b, true);
}

void    cases_short_stack(t_stack **a, t_stack **b)
{
    if (lenght_stack(*a) == 2)
        swap(a, true, true);
    else if (lenght_stack(*a) == 3)
        three_stack(a);
    else if (lenght_stack(*a) == 4)
        four_stack(a, b);
    else if (lenght_stack(*a) == 5)
        five_stack(a, b);
}
