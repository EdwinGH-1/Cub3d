/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:48:51 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/04 20:53:51 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int ch;
	
	for (ch = 0; ch <= 127; ch++) 
	{
      printf("%d ", ch);
      if (ft_isprint(ch)) 
	  {
         printf("The character is printable '%c'\n", ch);
      } 
	  else 
	  {
         printf("Cannot be printed\n");
      }
   }
   return 0;
}
*/
