/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:07:26 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 22:15:06 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (start > ft_strlen(s))
	{
		sub_str = ft_strdup("");
		return (sub_str);
	}
	sub_str = malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str = "Bonjour Marseille !";
    char *res;

    printf("Chaine originale : \"%s\"\n\n", str);

    // Test 1 : Extraction classique au milieu
    res = ft_substr(str, 8, 9);
    printf("Test 1 (start=8, len=9)   : \"%s\" (Attendu: \"Marseille\")\n", res);
    free(res);

    // Test 2 : Longueur demandée plus grande que la fin de la chaîne
    res = ft_substr(str, 8, 50);
    printf("Test 2 (start=8, len=50)  : \"%s\" (Attendu: \"Marseille !\")\n", 
			res);
    free(res);

    // Test 3 : Index de départ en dehors de la chaîne
    res = ft_substr(str, 30, 5);
    printf("Test 3 (start=30, len=5)  : \"%s\" (Attendu: \"\")\n", res);
    free(res);

    // Test 4 : Longueur de 0
    res = ft_substr(str, 0, 0);
    printf("Test 4 (start=0, len=0)   : \"%s\" (Attendu: \"\")\n", res);
    free(res);

    return (0);
}
*/
