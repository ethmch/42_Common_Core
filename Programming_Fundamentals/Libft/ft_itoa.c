/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:59:03 by emechali          #+#    #+#             */
/*   Updated: 2026/11/15 19:27:14 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		digits;
	long	value;

	value = n;
	digits = ft_count_digits(value);
	nbr = malloc(sizeof(char) * (digits + 1));
	if (nbr == NULL)
		return (NULL);
	nbr[digits] = '\0';
	if (value < 0)
	{
		nbr[0] = '-';
		value *= -1;
	}
	if (value == 0)
		nbr[0] = '0';
	while (value > 0)
	{
		digits--;
		nbr[digits] = '0' + (value % 10);
		value /= 10;
	}
	return (nbr);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *p;
	p = ft_itoa(-255);
	printf("The result of ft_itoa(-255) is %s\n", p);
	p = ft_itoa(0);
	printf("The result of ft_itoa(0) is %s\n", p);
	p = ft_itoa(42);
	printf("The result of ft_itoa(42) is %s\n", p);
	return 0;
}
*/
