/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:40:26 by emechali          #+#    #+#             */
/*   Updated: 2026/11/13 15:35:50 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;
	size_t	i;

	len_little = ft_strlen(little);
	i = 0;
	if (len_little == 0)
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[0] && (i + len_little) <= len)
		{
			if (ft_strncmp(big + i, little, len_little) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*phrase = "Bonjour tout le monde, bienvenue en C !";

	// Test 1 : Recherche classique réussie
	printf("Test 1 (trouve)       : %s\n", ft_strnstr(phrase, "monde", 25));

	// Test 2 : Sous-chaîne présente mais trop loin par rapport à 'len'
	printf("Test 2 (trop loin)    : %s\n", ft_strnstr(phrase, "monde", 18));

	// Test 3 : Sous-chaîne coupée pile à la limite 'len' (doit renvoyer NULL)
	printf("Test 3 (coupe limite) : %s\n", ft_strnstr(phrase, "monde", 20));

	// Test 4 : Sous-chaîne vide (doit renvoyer le début de 'phrase')
	printf("Test 4 (little vide)  : %s\n", ft_strnstr(phrase, "", 10));

	// Test 5 : Longueur 'len' à 0 avec une recherche non vide
	printf("Test 5 (len = 0)      : %s\n", ft_strnstr(phrase, "Bonjour", 0));

	// Test 6 : Longueur 'len' à 0 avec une sous-chaîne 
	// vide (doit renvoyer 'phrase')
	printf("Test 6 (len=0 + vide) : %s\n", ft_strnstr(phrase, "", 0));

	// Test 7 : Sous-chaîne inexistante
	printf("Test 7 (inexistant)   : %s\n", ft_strnstr(phrase, "Python", 40));

	// Test 8 : 'len' beaucoup plus grand que la taille réelle de 'phrase'
	printf("Test 8 (len immense)  : %s\n", ft_strnstr(phrase, "C !", 1000));

	return (0);
}
*/
