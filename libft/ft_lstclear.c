/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:07:53 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/05 17:47:50 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*test;

	if (!lst)
		return ;
	test = NULL;
	while (*lst)
	{
		test = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = test;
	}
	*lst = NULL;
}

// char	*set_arg(char *str)
// {
// 	int i;
// 	int	j;
// 	char *p;

// 	i = 0;
// 	while (i < ft_strlen(str))
// 		i++;
// 	p = malloc(sizeof(char) * (i + 1));
// 	j = 0;
// 	while (j <= i)
// 	{
// 		p[j] = str[j];
// 		j++; 
// 	}
// 	p[j] = '\0';
// 	return (p);
// }

// int main()
// {
// 	int x = 10;
// 	int y = 10;
// 	int z = 10;

// 	t_list	*node_1 = ft_lstnew(malloc(sizeof(int))); 
// 	t_list	*node_2 = ft_lstnew(malloc(sizeof(int)));
// 	t_list	*node_3 = ft_lstnew(malloc(sizeof(int)));

// 	*(int *)(node_1->content) = 10;
// 	*(int *)(node_2->content) = 20;
// 	*(int *)(node_3->content) = 30;

// 	if (!node_1 || !node_2 || !node_3)
// 		return (0);
// 	node_1->next = node_2;
// 	node_2->next = node_3;

// 	t_list *aid_node = node_1;
// 	while (aid_node)
// 	{
// 		printf("node nbr = %d\n", *(int *)aid_node->content);
// 		aid_node = aid_node->next;
// 	}

// 	ft_lstclear(&node_1,delete);

// 	if (!node_1)
// 		printf("good clear");
// 	else
// 		printf("memoire crach");
// }

// char	*set_str(char *p, char *str)
// {
// 	int i;
// 	int	j;

// 	i = 0;
// 	while (i <= ft_strlen(str))
// 		i++;
// 	p = malloc(sizeof(char) * i);
// 	j = 0;
// 	while (j < i)
// 	{
// 		p[j] = str[j];
// 		j++; 
// 	}
// 	p[j] = '\0';
// 	return (p);
// }

// int main()
// {
// 	// char s1[] = "hamza";
// 	// char s2[] = "ezzahi";
// 	// char s3[] = "hiba";

// 	t_list	*node_1 = ft_lstnew(strdup(s1)); 
// 	t_list	*node_2 = ft_lstnew(strdup(s2));
// 	t_list	*node_3 = ft_lstnew(strdup(s3));

// 	if (!node_1 || !node_2 || !node_3)
// 		return (0);
// 	node_1->next = node_2;
// 	node_2->next = node_3;


// 	ft_lstclear(&node_1,delete);

// 	// t_list *aid_node = node_1;
// 	// while (aid_node)
// 	// {
// 	// 	printf("%p\n", aid_node->next);
// 	// 	aid_node = aid_node->next;
// 	// }

// 	if (!node_1)
// 		printf("good clear");
// 	else
// 		printf("memoire crach");
// }