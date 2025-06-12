/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:19:02 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/04 20:32:19 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	char *a = "Linux is the best!";
	char *b = "11 charssss";

	printf("%s has chars %zu\n", a, ft_strlen(a));
	printf("%s has chars %zu\n", b, ft_strlen(b));
	return (0);
}
*/
