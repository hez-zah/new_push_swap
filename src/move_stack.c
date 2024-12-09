#include "../push_swap.h"

t_stack *find_cheapest(t_stack **b)
{
    t_stack *cheapest;

    cheapest = *b;
    while (cheapest)
    {
        if (cheapest->cheapest == true)
            return cheapest;
        cheapest = cheapest->next;
    }
    return (NULL);
}

void    rest_rotation_a(t_stack **a, t_stack *cheapest)
{
    while (cheapest->index)
    {
        if (cheapest->abov_medlan)
            rotate(a, true, true);
        else
            rrotate(a, true, true);
    }
}

void    rest_rotation_b(t_stack **b, t_stack *cheapest)
{
    while (cheapest->index)
    {
        if (cheapest->abov_medlan)
            rotate(b, true, false);
        else
            rrotate(b, true, false);
    }
}

void    move_stack(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    cheapest = find_cheapest(b);
    if (!cheapest->abov_medlan && !cheapest->target_node->abov_medlan)
            while (cheapest != *b && cheapest->target_node != *a)
                double_rrotate(a, b);
    else if (cheapest->abov_medlan && cheapest->target_node->abov_medlan)
            while (cheapest != *b && cheapest->target_node != *a)
                double_rotate(a, b);
    rest_rotation_b(b, cheapest);
    rest_rotation_a(a, cheapest->target_node);
    push(a, b, true);
}

    // t_stack *tmp = *b;
    // while (tmp)
    // {
    //     printf("{%d|%d} | {%d|%d}\n", tmp->nbr, tmp->abov_medlan, tmp->target_node->nbr, tmp->target_node->abov_medlan);
    //     tmp = tmp->next;
    // }
    // printf("\n=======>%d | %d \n", cheapest->nbr, cheapest->target_node->nbr);

    // if (!cheapest->abov_medlan && !cheapest->target_node->abov_medlan)
    // {
    //     // printf("=======>%d | %d \n", cheapest->index, cheapest->target_node->index);
    //         // while (cheapest->index && cheapest->target_node->index)
    //         //     double_rrotate(a, b);
    //         while (cheapest != *b && cheapest->target_node != *a)
    //             double_rrotate(a, b);
    // }
    // else if (cheapest->abov_medlan && cheapest->target_node->abov_medlan)
    // {
    //     // printf("------->%d | %d \n", cheapest->index, cheapest->target_node->index);
    //         while (cheapest != *b && cheapest->target_node != *a)
    //             double_rotate(a, b);
    //         // while (cheapest->index && cheapest->target_node->index)
    //         //     double_rotate(a, b);
    // }