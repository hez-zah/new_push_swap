#include "../push_swap.h"

static int find_maxlengh_index(t_stack *list)
{
    int max;
    int index_max;

    max = list->len;
    index_max = 0;
    while (list)
    {
        if (max <= list->len)
        {
            max = list->len;
            index_max = list->index;
        }
        list = list->next;
    }
    return (index_max);
}

static int find_maxlengh(t_stack *list, int index_max)
{
    t_stack *tmp;

    tmp = list;
    while (tmp)
    {
        if (tmp->index == index_max)
            break ;
        tmp = tmp->next;
    }
    return (tmp->len);
}

static void    find_lis(t_stack *list, int index_max)
{
    t_stack *tmp;
    int     len_max;
    int     i;

    len_max = find_maxlengh(list, index_max);
    i = -1;
    while (++i < len_max)
    {
        tmp = list;
        while (tmp)
        {
            if (tmp->index == index_max)
            {
                index_max = tmp->sub;
                tmp->lis = true;
            }
            tmp = tmp->next;
        }
    }
}

void    lis(t_stack **list)
{
    t_stack *tmp_i;
    t_stack *tmp_j;

    tmp_j = *list;
    tmp_i = tmp_j->next;
    while (tmp_i)
    {
        while (tmp_j->index < tmp_i->index)
        {
            if (tmp_j->nbr < tmp_i->nbr && tmp_j->len + 1 >= tmp_i->len)
            {
                tmp_i->len = tmp_j->len + 1;
                tmp_i->sub = tmp_j->index;
            }
            tmp_j = tmp_j->next;
        }
        tmp_i = tmp_i->next;
        tmp_j = *list;
    }
    find_lis(*list, find_maxlengh_index(*list));
}