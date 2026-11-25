/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:58:24 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 21:04:38 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t dest_size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(source);
	if (dest_size == 0 || source == NULL)
		return (len_src);
	while (source[i] && i + 1 < (dest_size))
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}
/*
#include <stdio.h>
#include <string.h>

int main() {

    char buffer[];
    size_t needed = strlcpy( buffer, "KooR.fr", sizeof buffer );

    printf( "%s\n", buffer );
    printf( "taille source : %zu\n", needed );

    return 0;
}
*/
