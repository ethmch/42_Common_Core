/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:44:17 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 20:21:06 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, len_s1);
	ft_memcpy(new_str + len_s1, s2, len_s2 + 1);
	return (new_str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*tab;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * 4);
	strs[0] = "salut ";
	strs[1] = "le sang";
	tab = ft_strjoin(strs[0], strs[1]);
	printf("%s\n", tab);
	free(strs);
	free(tab);
	return (0);
}
*/
