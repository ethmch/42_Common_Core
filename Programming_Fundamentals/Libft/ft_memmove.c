/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:32:47 by emechali          #+#    #+#             */
/*   Updated: 2026/11/11 14:53:33 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		i = count;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		i = 0;
		while (i < count)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*
int	main()
{
	char a[] = "Bonjour";
	
	printf("%s\n", a);
	ft_memmove(a + 2, a, 4);
	printf("%s\n", a);
}
*/
