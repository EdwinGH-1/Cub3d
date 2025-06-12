/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 07:53:49 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 09:59:17 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

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

static bool	ft_isset(char const s1, char const *set)
{
	size_t	ind;

	ind = 0;
	while (set[ind] != '\0')
	{
		if (s1 == set[ind])
		{
			return (true);
		}
		ind++;
	}
	return (false);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	ind;

	if (ft_strlen(s) - start <= len)
	{
		sub = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	}
	else
	{
		sub = malloc(sizeof(char) * (len + 1));
	}
	if (sub == NULL)
	{
		return (NULL);
	}
	ind = 0;
	while (s[start + ind] != '\0' && ind < len)
	{
		sub[ind] = s[start + ind];
		ind++;
	}
	sub[ind] = '\0';
	return (sub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[start], set))
	{
		start++;
	}
	while (ft_isset(s1[end], set))
	{
		end--;
	}
	return (ft_substr(s1, start, end - start + 1));
}

/*
#include <stdio.h>
int	main(void)
{
	//Test 1
	char	s1[] = "*(@abcdef*(@";
	char	set1[] = "*(@";
	printf("s1 = %s, set = %s\n", s1, set1);
	printf("trim = %s\n\n", ft_strtrim(s1, set1));

	//Test 2
	char	s2[] = "*(@abc*(@def*(@";
	char	set2[] = "*(@";
	printf("s1 = %s, set = %s\n", s2, set2);
	printf("trim = %s\n\n", ft_strtrim(s2, set2));

	//Test 3
	char	s3[] = "*(@*(@";
	char	set3[] = "*(@";
	printf("s1 = %s, set = %s\n", s3, set3);
	printf("trim = %s\n\n", ft_strtrim(s3, set3));

	//Test 4
	char	s4[] = "*(@abcdef*(@";
	char	set4[] = "";
	printf("s1 = %s, set = %s\n", s4, set4);
	printf("trim = %s\n\n", ft_strtrim(s4, set4));

	//Test 5
	char	s5[] = "";
	char	set5[] = "*(@";
	printf("s1 = %s, set = %s\n", s5, set5);
	printf("trim = %s\n\n", ft_strtrim(s5, set5));

	//Test 6
	char	s6[] = "";
	char	set6[] = "";
	printf("s1 = %s, set = %s\n", s6, set6);
	printf("trim = %s\n", ft_strtrim(s6, set6));
	return (0);
}
*/
