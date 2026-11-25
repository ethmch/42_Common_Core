/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:35:48 by emechali          #+#    #+#             */
/*   Updated: 2026/11/11 14:04:26 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#define  BUF_SIZE  20

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*dest;
	unsigned char	c;
	size_t			i;

	dest = (unsigned char *)pointer;
	c = (unsigned char)value;
	i = 0;
	while (i < count)
	{
		dest[i] = c;
		i++;
	}
	return (pointer);
}

/*
int main(void)
{
   char buffer[BUF_SIZE + 1];
   char *string;
 
   ft_memset(buffer, 0, sizeof(buffer));
   string = (char *) ft_memset(buffer,'A', 10);
   printf("\nBuffer contents: %s\n", string);
   ft_memset(buffer+10, 'B', 10);
   printf("\nBuffer contents: %s\n", buffer);
}
*/

/*
int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    size_t size = sizeof( int ) * 5;
    int length;

    // Display the initial values //
    for( length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    // Reset the memory bloc //
    ft_memset( array, 0, size );

    // Display the new values //
    for( length=0; length<5; length++)
        printf( "%d ", array[ length ] );
    printf( "\n" );
    
    return 0;
}
*/
