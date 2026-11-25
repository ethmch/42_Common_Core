/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:42:24 by emechali          #+#    #+#             */
/*   Updated: 2026/11/13 12:24:59 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < count)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*
int	main()
{
	char src[20] = "allez l'om";
	char dest[20] = "tier  le sang";

	printf("src : %s\n", src);
	printf("dest : %s\n", dest);
	ft_memcpy(dest, src, 5);
	printf("%s\n", dest);
}
*/
