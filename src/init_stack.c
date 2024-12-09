#include "../push_swap.h"

void    set_target_node(t_stack *a, t_stack *b)
{
    t_stack *target_node;
    t_stack *current_node;
    long    max_indx;

    while (b)
    {
        max_indx = LONG_MAX;
        current_node = a;
        while (current_node)
        {
            if (current_node->nbr < max_indx && current_node->nbr > b->nbr)
            {
                target_node = current_node;
                max_indx = current_node->nbr;
            }
            current_node = current_node->next;
        }
        if (max_indx == LONG_MAX)
            b->target_node = small_node(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void    set_abov_medlan(t_stack *list)
{
    int len;
    t_stack *head;

    len = lenght_stack(list);
    head = list;
    while (head)
    {
        if (head->index <= (len / 2))
            head->abov_medlan = true;
        else
            head->abov_medlan = false;
        head = head->next;
    }
}

void    set_push_price(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;

    len_a = lenght_stack(a);
    len_b = lenght_stack(b);
    while (b)
    {
        b->push_price = b->index;
        if (!b->abov_medlan)
            b->push_price = len_b - b->index;
        if (b->target_node->abov_medlan)
            b->push_price += b->target_node->index;
        else
            b->push_price += len_a - b->target_node->index;
        b = b->next;
    }
}

void    set_cheapest(t_stack *b)
{
    int     cheap_price;
    t_stack *test;

    if (!b)
        return ;
    cheap_price = b->push_price + 1;
    test = b;
    while (b)
    {
        if (b->push_price < cheap_price)
        {
            test->cheapest = false;
            test = b;
            b->cheapest = true;
            cheap_price = b->push_price;
        }
        else
            b->cheapest = false;
        b = b->next;
    }
}

void    init_stack(t_stack **a, t_stack **b)
{
    set_target_node(*a, *b);
    set_abov_medlan(*a);
    set_abov_medlan(*b);
    set_push_price(*a, *b);
    set_cheapest(*b);
}
