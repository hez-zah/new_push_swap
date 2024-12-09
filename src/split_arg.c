#include "../push_swap.h"

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
