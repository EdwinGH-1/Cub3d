/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:06:22 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 12:15:11 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	ind;

	ind = 0;
	while (s[ind] != '\0')
	{
		f(ind, &s[ind]);
		ind++;
	}
}

/*
#include <stdio.h>
void	ft_print(unsigned int n, char *c)
{
	printf("Index: %u, Char: %c\n", n, *c);
}

int	main(int argc, char *argv[])
{
	int	i = argc;
	i = 2;
	ft_striteri(argv[1], ft_print);
}
*/	
