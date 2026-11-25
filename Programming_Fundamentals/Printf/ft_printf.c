/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:29:44 by emechali          #+#    #+#             */
/*   Updated: 2026/11/19 16:51:13 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_params(char c, va_list *ap)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_putchar(va_arg(*ap, int));
	if (c == 's')
		size += ft_putstr(va_arg(*ap, char *));
	if (c == 'p')
		size += ft_putptr(va_arg(*ap, void *));
	if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(*ap, int));
	if (c == 'u')
		size += ft_putnbr(va_arg(*ap, unsigned int));
	if (c == 'x' || c == 'X')
		size += ft_put_in_hexa(va_arg(*ap, unsigned int), c);
	if (c == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;

	if (format == NULL)
		return (-1);
	size = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				va_end(ap);
				return (-1);
			}
			size += ft_put_params(*format, &ap);
		}
		else
			size += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (size);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		ret_orig;
	int		ret_ft;
	int		x = 42;
	char	*str_null = NULL;
	void	*ptr_null = NULL;

	printf("=== 1. TEST %%c (Caractere) ===\n");
	ret_orig = printf("ORIG : [%c] [%c] [%c]\n", 'A', '0', '\n');
	ret_ft   = ft_printf("MINE : [%c] [%c] [%c]\n", 'A', '0', '\n');
	printf("Retours -> Orig: %d | Mine: %d\n\n", ret_orig, ret_ft);

	printf("=== 2. TEST %%s (Chaine de caracteres) ===\n");
	ret_orig = printf("ORIG : [%s] [%s] [%s]\n", "Bonjour", "", str_null);
	ret_ft   = ft_printf("MINE : [%s] [%s] [%s]\n", "Bonjour", "", str_null);
	printf("Retours -> Orig: %d | Mine: %d\n\n", ret_orig, ret_ft);

	printf("=== 3. TEST %%p (Pointeur) ===\n");
	ret_orig = printf("ORIG : [%p] [%p] [%p]\n",
	&x, ptr_null, (void *)ULONG_MAX);
	ret_ft   = ft_printf("MINE : [%p] [%p] [%p]\n",
	&x, ptr_null, (void *)ULONG_MAX);
	printf("Retours -> Orig: %d | Mine: %d\n\n",
	ret_orig, ret_ft);

	printf("=== 4. TEST %%d et %%i (Entiers signes) ===\n");
	ret_orig = printf("ORIG : [%d] [%i] [%d] [%i]\n",
	0, -42, INT_MIN, INT_MAX);
	ret_ft   = ft_printf("MINE : [%d] [%i] [%d] [%i]\n",
	0, -42, INT_MIN, INT_MAX);
	printf("Retours -> Orig: %d | Mine: %d\n\n", ret_orig, ret_ft);

	printf("=== 5. TEST %%u (Entier non signe) ===\n");
	ret_orig = printf("ORIG : [%u] [%u] [%u]\n", 0, 42, UINT_MAX);
	ret_ft   = ft_printf("MINE : [%u] [%u] [%u]\n", 0, 42, UINT_MAX);
	printf("Retours -> Orig: %d | Mine: %d\n\n", ret_orig, ret_ft);

	printf("=== 6. TEST %%x et %%X (Hexadecimal) ===\n");
	ret_orig = printf("ORIG : [%x] [%X] [%x] [%X]\n", 0, 0, 255, UINT_MAX);
	ret_ft   = ft_printf("MINE : [%x] [%X] [%x] [%X]\n",
	0, 0, 255, UINT_MAX);
	printf("Retours -> Orig: %d | Mine: %d\n\n", ret_orig, ret_ft);

	printf("=== 7. TEST %%%% (Pourcentage) ===\n");
	ret_orig = printf("ORIG : [%%] [%%%%] [100%%]\n");
	ret_ft   = ft_printf("MINE : [%%] [%%%%] [100%%]\n");
	printf("Retours -> Orig: %d | Mine: %d\n\n", ret_orig, ret_ft);

	printf("=== 8. TEST MIXTE ===\n");
	ret_orig = printf("ORIG : %c %s %p %d %i %u %x %X %%\n",
	'Z', "42", &x, -10, 10, 42, 42, 42);
	ret_ft   = ft_printf("MINE : %c %s %p %d %i %u %x %X %%\n",
	'Z', "42", &x, -10, 10, 42, 42, 42);
	printf("Retours -> Orig: %d | Mine: %d\n", ret_orig, ret_ft);

	return (0);
}
*/
