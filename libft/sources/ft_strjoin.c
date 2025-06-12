/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 07:44:50 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 09:58:21 by jthiew           ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		ind;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
	{
		return (NULL);
	}
	ind = 0;
	while (*s1 != '\0')
	{
		join[ind] = *s1;
		ind++;
		s1++;
	}
	while (*s2 != '\0')
	{
		join[ind] = *s2;
		ind++;
		s2++;
	}
	join[ind] = '\0';
	return (join);
}

/*
#include <stdio.h>
int	main(void)
{
	//Test 1
	char	s1[] = "abc";
	char	s2[] = "123";
	printf("s1 = %s, s2 = %s, joined str = %s\n", s1, s2, ft_strjoin(s1, s2));

	//Test 2
	char	s3[] = "";
	char	s4[] = "123";
	printf("s1 = %s, s2 = %s, joined str = %s\n", s3, s4, ft_strjoin(s3, s4));

	//Test 3
	char	s5[] = "abc";
	char	s6[] = "";
	printf("s1 = %s, s2 = %s, joined str = %s\n", s5, s6, ft_strjoin(s5, s6));

	//Test 4
	char	s7[] = "";
	char	s8[] = "";
	printf("s1 = %s, s2 = %s, joined str = %s\n", s7, s8, ft_strjoin(s7, s8));
	return (0);
}
*/
