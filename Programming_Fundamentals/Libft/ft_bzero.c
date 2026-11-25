/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:21:34 by emechali          #+#    #+#             */
/*   Updated: 2026/11/11 14:03:39 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_bzero(void *pointer, size_t count)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)pointer;
	i = 0;
	while (i < count)
	{
		p[i] = 0;
		i++;
	}
	return (pointer);
}

/*
int	main()
{
	char	buffer[40] = "Hello";

	ft_bzero(buffer, 3);
	printf("%d %d %d %c %c\n", buffer[0], buffer[1], buffer[2], 
	buffer[3], buffer[4]);
	return (0);
}
*/
