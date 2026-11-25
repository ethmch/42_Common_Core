/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:06:38 by emechali          #+#    #+#             */
/*   Updated: 2026/11/19 16:40:12 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long nb)
{
	int		size;

	size = 0;
	if (nb < 0)
	{
		size += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		size += ft_putchar(nb + '0');
	if (nb > 9)
	{
		size += ft_putnbr(nb / 10);
		size += ft_putnbr(nb % 10);
	}
	return (size);
}

int	ft_putstr(char *s)
{
	int	size;

	size = 0;
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		size += ft_putchar(*s);
		s++;
	}
	return (size);
}

int	ft_putptr(void *p)
{
	int				size;
	unsigned long	ptr;

	size = 0;
	if (p == NULL)
	{
		size += ft_putstr("(nil)");
		return (size);
	}
	ptr = (unsigned long) p;
	size += ft_putchar('0');
	size += ft_putchar('x');
	size += ft_put_in_hexa(ptr, 'x');
	return (size);
}
