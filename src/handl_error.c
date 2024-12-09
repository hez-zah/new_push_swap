#include "../push_swap.h"

int	double_nbr(char **sp)
{
	int	i;
	int	j;

	if (!(*sp))
		return (write(1, "Error\n", 6), 0);
	i = -1;
	while (sp[++i])
	{
		j = i;
		while (sp[++j])
			if (ft_atoi(sp[i]) == ft_atoi(sp[j]))
				return (write(1, "Error\n", 6), 0);
	}
	return (1);
}

int	non_number(char **sp)
{
	int			i;
	int			l;
	static int	j;

	l = -1;
	while (sp[++l])
	{
		i = -1;
        j = 0;
		while (sp[l][++i])
		{
			if ((sp[l][i] == '-' || sp[l][i] == '+') && !j++)
				i++;
			if (!ft_isdigit(sp[l][i]))
				return (write(1, "Error\n", 6), 0);
		}
	}
	return (1);
}

char	**handl_error(int ac, char *av[])
{
	char **sp = concat_arg(ac, av);

	if (!double_nbr(sp) || !non_number(sp))
	{
		fr_double(sp);
		exit (1);
	}
	return (sp);
}

bool    sort_stack(t_stack *list)
{
    if (!list)
        return (true);
    while (list->next)
    {
        if (list->nbr > list->next->nbr)
            return (false);
        list = list->next;
    }
    return (true);
}