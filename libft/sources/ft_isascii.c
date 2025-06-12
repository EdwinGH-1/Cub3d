/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:36:05 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/04 20:48:14 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0x00 && c <= 0x7f)
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

   for (ch = 0x00; ch <= 0x82; ch++) {
      printf("%#04x    ", ch);
      if (ft_isascii(ch)) {
         printf("The character is '%c'\n", ch);
      } else {
         printf("Cannot be represented by an ASCII character\n");
      }
   }
   return 0;
}
*/
