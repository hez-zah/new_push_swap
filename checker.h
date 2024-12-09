#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include "libft/libft.h"
#include "src_bonus/g_n_l/get_next_line.h"

typedef struct s_stack
{
	int     index;
	int     nbr;
	struct  s_stack *next;
}t_stack;

char    **concat_arg(int ac, char *av[]);
//error
char	**handl_error(int ac, char *av[]);
//free
void	fr_double(char **p);
void	fr_single(char *str1, char *str2);
void    fr_stacks(t_stack *a, t_stack *b);
//creat_stack
t_stack *creat_stack(char **sp);
t_stack *lstnew(void *content, int index);
t_stack *lstlast(t_stack *lst);
void    lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
//moves
void    push(t_stack **a, t_stack **b);
void    rotate(t_stack **a);
void    double_rotate(t_stack **a, t_stack **b);
void    rrotate(t_stack **a);
void    double_rrotate(t_stack **a, t_stack **b);
void    swap(t_stack **a);
void    double_swap(t_stack **a, t_stack **b);
///
bool    sort_stack(t_stack *list);
# endif
