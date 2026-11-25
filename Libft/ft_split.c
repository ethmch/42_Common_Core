/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:09:32 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 20:00:36 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int	ft_lenword(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*ft_free_words(char **set, int j)
{
	while (j >= 0)
	{
		free(set[j]);
		j--;
	}
	free(set);
	return (NULL);
}

static int	ft_fill_word(char **set, int j, char const *s, char c)
{
	int	i;

	i = 0;
	set[j] = malloc(sizeof(char) * (ft_lenword(s, c) + 1));
	if (set[j] == NULL)
		ft_free_words(set, j);
	while (s[i] && s[i] != c)
	{
		set[j][i] = s[i];
		i++;
	}
	set[j][i] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**set;
	int		j;

	if (!s)
		return (NULL);
	set = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (set == NULL)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			s += ft_fill_word(set, j, s, c);
			j++;
		}
		else
			s++;
	}
	set[j] = NULL;
	return (set);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype de ta fonction (ou inclus "libft.h") //
char	**ft_split(char const *s, char c);

// Compare le résultat de ft_split avec un tableau attendu //
void	check_split(int id, char const *s, char c, char **expected)
{
	char	**res;
	int		i;
	int		ok;

	res = ft_split(s, c);
	ok = 1;
	if (!res && !expected)
	{
		printf("[OK] Test %d (NULL attendu)\n", id);
		return ;
	}
	if (!res || !expected)
	{
		printf("[KO] Test %d : NULL inattendu\n", id);
		return ;
	}
	i = 0;
	while (expected[i] && res[i])
	{
		if (strcmp(res[i], expected[i]) != 0)
			ok = 0;
		free(res[i]);
		i++;
	}
	if (expected[i] != NULL || res[i] != NULL)
		ok = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	if (ok)
		printf("[OK] Test %d\n", id);
	else
		printf("[KO] Test %d : contenu ou taille incorrecte\n", id);
}

int	main(void)
{
	char	*exp1[] = {"Hello", "World", "42", NULL};
	char	*exp2[] = {"42", NULL};
	char	*exp3[] = {NULL};
	char	*exp5[] = {"Test", "zero", NULL};

	// Tests standards et limites //
	check_split(1, "Hello World 42", ' ', exp1);
	check_split(2, "   Hello   World   42   ", ' ', exp1);
	check_split(3, "42", ' ', exp2);
	check_split(4, "   42   ", ' ', exp2);
	check_split(5, "        ", ' ', exp3);
	check_split(6, "", ' ', exp3);
	check_split(7, "Un\0mot\0seul", ' ', (char *[]){"Un", NULL});
	check_split(8, "Test\nzero", '\n', exp5);
	check_split(9, "RienACouper", '\0', (char *[]){"RienACouper", NULL});
	check_split(10, "", '\0', exp3);
	check_split(11, NULL, ' ', NULL);

	return (0);
}
*/
