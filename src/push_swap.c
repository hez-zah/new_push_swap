#include "../push_swap.h"

bool    just_lis(t_stack *a)
{
    while (a)
    {
        if (a->lis == false)
            return (true);
        a = a->next;
    }
    return (false);
}

void    push_non_lis(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    while (just_lis(*a))
    {
        set_abov_medlan(*a);
        tmp = *a;
        while (tmp->lis)
            tmp = tmp->next;
        if (!tmp->lis && !tmp->abov_medlan)
            while (tmp != *a)
                rrotate(a, true, true);
        if ((*a)->lis)
            rotate(a, true, true);
        else
            push(b, a, false);
    }
}

static void    cases_long_stack(t_stack **a, t_stack **b)
{
    t_stack *samller;

    push_non_lis(a,b);
    while (*b)
    {
        init_stack(a, b);
        move_stack(a, b);
    }
    samller = small_node(*a);
    if (samller->abov_medlan)
        while (samller->index)
            rotate(a, true, true);
    else
        while (samller->index)
            rrotate(a, true, true);
}

void    push_swap(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;

    a = creat_stack(handl_error(ac, av));
    b = NULL;
    if (lenght_stack(a) <= 5)
        cases_short_stack(&a, &b);
    else
        cases_long_stack(&a, &b);
    fr_stacks(a, b);
}

// void    ff(){system("leaks push_swap");}

int main(int ac, char *av[])
{
    // atexit(ff);
    if (ac > 1)
        push_swap(ac, av);
}

    // printf("-------\n");
    // t_stack *tmp = a;
    // while (tmp)
    // {
    //     printf("%d \n", tmp->nbr);
    //     tmp = tmp->next;
    // }
    // printf("--------\n");
    // tmp = b;
    // while (tmp)
    // {
    //     printf("%d | %d\n", tmp->nbr, tmp->target_node->nbr);
    //     tmp = tmp->next;
    // }
    // printf("--------\n");
