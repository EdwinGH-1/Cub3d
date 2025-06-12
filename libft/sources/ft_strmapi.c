/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:07:21 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 10:01:41 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	ind;
	size_t	len;
	char	*str;

	ind = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (ind < len)
	{
		str[ind] = f(ind, s[ind]);
		ind++;
	}
	str[ind] = '\0';
	return (str);
}

/*
#include <stdio.h>
char	shift1(unsigned int n, char c)
{
	printf("Index: %u, Char: %c\n", n, c);
	return (c + 1);
}

int	main(int argc, char *argv[])
{
	int	i = argc;
	i = 2;
	printf("Original Str: %s\n", argv[1]);
	char *str = ft_strmapi(argv[1], shift1);
	printf("New Str: %s\n", str);
}
*/
