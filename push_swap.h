#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_stack
{
    int     index;
    int     nbr;
    int     len;
    int     sub;
    bool    lis;
    int     push_price;
    bool    abov_medlan;
    bool    cheapest;
    struct  s_stack *target_node;
    struct  s_stack *next;
}t_stack;

void    push_swap(int ac, char *av[]);
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
///lis
void    lis(t_stack **list);

//moves
void    push(t_stack **a, t_stack **b, bool sign);
void    rotate(t_stack **a, bool sig, bool a_b);
void    double_rotate(t_stack **a, t_stack **b);
void    rrotate(t_stack **a, bool sig, bool a_b);
void    double_rrotate(t_stack **a, t_stack **b);
void    swap(t_stack **a, bool sig, bool a_b);
void    double_swap(t_stack **a, t_stack **b);
///medlin
void    set_abov_medlan(t_stack *list);
//sorted_stack
bool    sort_stack(t_stack *list);
//ranking index
void    index_sort(t_stack *list);
///lenght stack
int     lenght_stack(t_stack *list);
/// largest number in stack
long    highest_stack(t_stack *list);
/// smaller number in stack
long    smaller_stack(t_stack *list);
t_stack *small_node(t_stack *list);
///short stack
void    three_stack(t_stack **list);
// void    four_stack(t_stack **a, t_stack **b);
void    cases_short_stack(t_stack **a, t_stack **b);
///init stack
void    init_stack(t_stack **a, t_stack **b);
///move stack
void    move_stack(t_stack **a, t_stack **b);
# endif
