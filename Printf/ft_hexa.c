/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:22:16 by emechali          #+#    #+#             */
/*   Updated: 2026/11/19 15:58:52 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_in_hexa(unsigned long n, char c)
{
	char	*hexa_base;
	int		size;

	if (c == 'X')
		hexa_base = "0123456789ABCDEF";
	if (c == 'x')
		hexa_base = "0123456789abcdef";
	size = 0;
	if (n >= 16)
		size += ft_put_in_hexa(n / 16, c);
	size += ft_putchar(hexa_base[n % 16]);
	return (size);
}
