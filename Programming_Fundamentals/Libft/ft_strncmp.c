/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:47:25 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 21:15:26 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool startsWith( const char * theString, const char * theBase ) {
    return ft_strncmp( theString, theBase, strlen( theBase ) ) == 0;
}

int main() {

    printf( "\"toto\" starts with \"to\" == %d\n", startsWith( "toto", "to" ) );
    printf( "\"toto\" starts with \"james\" == %d\n", 
startsWith( "toto", "james" ) );
    printf( "\"james bond\" starts with \"james\" == %d\n", 
startsWith( "james bond", "james" ) );

    return 0;
}
*/
