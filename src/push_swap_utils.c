#include "../push_swap.h"

void    index_sort(t_stack *list)
{
    int i;

    i = -1;
    while (list)
    {
        list->index = ++i;
        list = list->next;
    }
}

int lenght_stack(t_stack *list)
{
    int i;

    i = 0;
    while (list)
    {
        i++;
        list = list->next;
    }
    return (i);
}

long    highest_stack(t_stack *list)
{
    long high;

    high = list->nbr;
    while (list)
    {
        if (list->nbr > high)
            high = list->nbr;
        list = list->next;
    }
    return (high);
}

long    smaller_stack(t_stack *list)
{
    long small;

    small = list->nbr;
    while (list)
    {
        if (list->nbr < small)
            small = list->nbr;
        list = list->next;
    }
    return (small);
}

t_stack *small_node(t_stack *list)
{
    long small;
    t_stack *small_node;

    small = list->nbr;
    while (list)
    {
        if (list->nbr <= small)
        {
            small = list->nbr;
            small_node = list;
        }
        list = list->next;
    }
    return (small_node);
}
