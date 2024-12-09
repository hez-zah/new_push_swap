#include "../checker.h"

void	fr_double(char **p)
{
	int i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

void	fr_single(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

static void	fr_stack(t_stack *a)
{
	t_stack *fr_stack;

	fr_stack = a;
	while (a)
	{
		a = a->next;
		free(fr_stack);
		fr_stack = a;
	}
}

void	fr_stacks(t_stack *a, t_stack *b)
{
	fr_stack(a);
	fr_stack(b);
}

char	**concat_arg(int ac, char *av[])
{
	int		i;
	char	*line;
	char	*fr_line;
	char	*fr_line2;
	char	**sp;

	i = 0;
	line = ft_strdup("");
	while (++i < ac)
	{
		fr_line = line;
		fr_line2 = ft_strjoin(av[i], " ");
		line = ft_strjoin(fr_line, fr_line2);
		fr_single(fr_line, fr_line2);
	}
	sp = ft_split(line, ' ');
	free(line);
	return (sp);
}
