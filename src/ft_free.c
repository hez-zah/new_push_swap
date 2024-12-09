#include "../push_swap.h"

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
