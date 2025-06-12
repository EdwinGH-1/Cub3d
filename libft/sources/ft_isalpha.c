/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:19:38 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/04 20:01:25 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int main(void)
{
  char  a1 = 'a';
  char  a2 = 'z';
  char  a3 = 'A';
  char  a4 = 'Z';
  char  a5 = '1';
  char  a6 = '_';

  printf("%c is alpha? %d\n", a1, ft_isalpha(a1));
  printf("%c is alpha? %d\n", a2, ft_isalpha(a2));
  printf("%c is alpha? %d\n", a3, ft_isalpha(a3));
  printf("%c is alpha? %d\n", a4, ft_isalpha(a4));
  printf("%c is alpha? %d\n", a5, ft_isalpha(a5));
  printf("%c is alpha? %d\n", a6, ft_isalpha(a6));
  return (0);
}
*/
