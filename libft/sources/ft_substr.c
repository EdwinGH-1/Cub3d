/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 07:17:03 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 09:57:20 by jthiew           ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	ind;

	if (start >= ft_strlen(s))
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s) - start <= len)
		sub = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ind = 0;
	while (s[start + ind] != '\0' && ind < len)
	{
		sub[ind] = s[start + ind];
		ind++;
	}
	sub[ind] = '\0';
	return (sub);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s[] = "0123456789";
	unsigned int	start = 0;
	size_t	len = 0;

	printf("String = %s, start = %u, len = %zu\n", s, start, len);
	printf("Substr = %s\n", ft_substr(s, start, len));

	return (0);
}

*/
