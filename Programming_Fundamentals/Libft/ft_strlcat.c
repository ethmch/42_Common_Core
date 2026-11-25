/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:18:28 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 20:51:28 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len == size)
		return (dest_len + src_len);
	i = 0;
	while (src[i] && (dest_len + i + 1 < size))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main() 
{
    char buffer[10] = "KooR";
    size_t needed = ft_strlcat( buffer, ".fr-demo", sizeof buffer );

    printf( "%s\n", buffer );
    printf( "taille necessaire : %zu\n", needed );

    return 0;
}
*/
