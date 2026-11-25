/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:34:30 by emechali          #+#    #+#             */
/*   Updated: 2026/11/13 14:41:03 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Le nom du fichier d'origine
    const char * originalFilename = "folder/image.jpg";

    // On prépare le nom du fichier de destination
    size_t size = strlen( originalFilename ) + 1;   // +1 pour le zéro terminal
    char * destinationFilename = (char *) malloc( size );
    strcpy( destinationFilename, originalFilename );

    // Et on y remplace l'extension du fichier par l'extension .png
    char * lastDotPos = ft_strrchr( destinationFilename, '.' );
    strcpy( lastDotPos, ".png" );

    // On affiche les deux noms de fichiers
    puts( originalFilename );
    puts( destinationFilename );

    return EXIT_SUCCESS;
}
*/
