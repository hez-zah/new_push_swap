/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:27:39 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/05/29 21:51:53 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_call(const char *led1, const char *led2, char *p)
{
	int	i;
	int	j;

	i = 0;
	while (led1[i] != '\0')
	{
		p[i] = led1[i];
		i++;
	}
	j = 0;
	while (led2[j] != '\0')
	{
		p[i] = led2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	p = malloc((ft_strlen (s1) + ft_strlen (s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	return (ft_call (s1, s2, p));
}
