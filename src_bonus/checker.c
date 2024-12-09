#include "../checker.h"

int read_line(t_stack **a, t_stack **b, char *line)
{
    if (!ft_strncmp(line, "sa\n", 3))
        swap(a);
    else if (!ft_strncmp(line, "sb\n", 3))
        swap(b);
    else if (!ft_strncmp(line, "ss\n", 3))
        double_swap(a, b);
    else if (!ft_strncmp(line, "ra\n", 3))
        rotate(a);
    else if (!ft_strncmp(line, "rb\n", 3))
        rotate(b);
    else if (!ft_strncmp(line, "rr\n", 3))
        double_rotate(a, b);
    else if (!ft_strncmp(line, "rra\n", 4))
        rrotate(a);
    else if (!ft_strncmp(line, "rrb\n", 4))
        rrotate(b);
    else if (!ft_strncmp(line, "rrr\n", 4))
        double_rrotate(a, b);
    else if (!ft_strncmp(line, "pa\n", 3))
        push(a, b);
    else if (!ft_strncmp(line, "pb\n", 3))
        push(b, a);
    else
        return (0);
    return (1);
}

void    checker(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;
    char    *line;

    a = creat_stack(handl_error(ac, av));
    b = NULL;
    while (1)
    {
        line = get_next_line(0);
        if (!read_line(&a, &b, line))
            break ;
        free(line);
    }
    free(line);
    if (sort_stack(a))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    fr_stacks(a, b);
}

int main(int ac, char *av[])
{
    if (ac > 1)
        checker(ac, av);
}
