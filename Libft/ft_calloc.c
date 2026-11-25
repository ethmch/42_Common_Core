/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emechali <emechali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:39:23 by emechali          #+#    #+#             */
/*   Updated: 2026/11/16 18:42:36 by emechali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;

	if (n != 0 && n > (size_t)-1 / size)
	{
		return (NULL);
	}
	ptr = malloc(size * n);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (n * size));
	return (ptr);
}

/*
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
  long * array;                          // start of the array            
  long * index;                          // index variable                
  int    i;                              // index variable                
  int  num;                              // number of entries of the array
 
  printf( "Enter the size of the array\n" );
  scanf( "%i", &num);
 
                                            // allocate num entries 
  if ( (index = array = (long *) ft_calloc( num, sizeof( long ))) != NULL )
  {
 
    for ( i = 0; i < num; ++i )             // put values in arr 
       *index++ = i;                        // using pointer no   
 
    for ( i = 0; i < num; ++i )             // print the array out  
      printf( "array[%i ] = %li\n", i, array[i] );
  }
  else
  { // out of storage 
    perror( "Out of storage" );
    abort();
  }
}
 
Enter the size of the array
array[ 0 ] = 0
array[ 1 ] = 1
array[ 2 ] = 2
*/
