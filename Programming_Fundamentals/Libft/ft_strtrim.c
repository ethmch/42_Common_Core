/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:51:16 by emechali          #+#    #+#             */
/*   Updated: 2026/11/15 17:08:22 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_is_in_set(set, s1[start]))
		start++;
	while (start < end && ft_is_in_set(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *source = " \t\n   Bonjour tout le monde !   \t\n ";
    const char *set = " \t\n"; // supprimer espaces, tabulations, retours ligne

    char *trimmed = ft_strtrim(source, set);

    if (trimmed)
    {
        printf("Avant : [%s]\n", source);
        printf("Après : [%s]\n", trimmed);
        free(trimmed); // Libération de la mémoire allouée par strtrim
    }
    else
    {
        printf("Erreur d'allocation mémoire.\n");
    }

    return (0);
}
*/
