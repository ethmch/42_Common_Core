/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:20:05 by emechali          #+#    #+#             */
/*   Updated: 2026/11/11 18:35:11 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (src1[i] > src2[i])
			return (1);
		if (src1[i] < src2[i])
			return (-1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char	*s1 = "ABCDEEEE";
	char	*s2 = "ABCEDFFF";
	printf("s1 : %s\n", s1);
	printf("s2 : %s\n", s2);
	printf("%d\n", ft_memcmp(s1, s2, 5));
}
*/
