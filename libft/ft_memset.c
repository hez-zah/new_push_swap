/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:21:27 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/11 17:36:02 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*led;

	led = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*(led + i) = (unsigned char)c;
		i++;
	}
	return (led);
}

int main()
{
    char buffer[4];
	int nb = 1337;
	char c;
	int i = 4;

	ft_memset(buffer + i, '\0', 1);
	while (nb > 0)
	{
		--i;
		c = (nb % 10) + '0';
		ft_memset(buffer + i, c, 1);
		nb /= 10;
	}
	printf("%s\n", buffer);
    return 0;
}