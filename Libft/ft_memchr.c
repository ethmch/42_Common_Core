/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:28:25 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 19:27:28 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		chr;
	size_t				i;

	s = (const unsigned char *)src;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == chr)
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *phrase = "Bonjour Marseille !";
    size_t longueur = strlen(phrase); // 19 caractères

    // Test 1 : Chercher une lettre présente ('M')
    char *res1 = (char *)ft_memchr(phrase, 'M', longueur);
    if (res1 != NULL) {
        printf("Test 1 : Trouve a l'index %ld -> \"%s\"\n", res1 - phrase, res1);
    }

    // Test 2 : Chercher un caractère absent ('z')
    char *res2 = (char *)ft_memchr(phrase, 'z', longueur);
    if (res2 == NULL) {
        printf("Test 2 : Le caractere 'z' est absent (NULL)\n");
    }

    // Test 3 : Chercher 'M' uniquement dans les 5 premiers caractères ("Bonjo")
    char *res3 = (char *)ft_memchr(phrase, 'M', 5);
    if (res3 == NULL) {
        printf("Test 3 : 'M' non trouve dans les 5premiers caracteres (NULL)\n");
    }

    return 0;
}
*/
