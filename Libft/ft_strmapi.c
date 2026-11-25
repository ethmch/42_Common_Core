/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 19:28:06 by emechali          #+#    #+#             */
/*   Updated: 2026/11/15 19:51:37 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		i;

	i = 0;
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
char    test(unsigned int i, char str)
{
    printf("My inner function: index = %d and %c\n", i, str);
    return (str);
}

char    test2(unsigned int i, char str)
{
    printf("My inner function2: index = %d and %c\n", i, str);
    return (str);
}

int main()
{
    char const *s1 = "Hello 42KL";
    char *p_strmapi1;
    char *p_strmapi2;
    p_strmapi1 = ft_strmapi(s1,test);
    p_strmapi2 = ft_strmapi(s1,test2);
    printf("test1: %s\n", p_strmapi1);
    printf("test2: %s\n", p_strmapi2);
    
    return 0;
}
*/
