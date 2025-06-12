/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:18:49 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/13 18:50:20 by jthiew           ###   ########.fr       */
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

static char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;
	size_t	i;

	len = ft_strlen(s);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*ft_strrev(char *s, int ind)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ind - 1;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
	return (s);
}

static char	*ft_count_digit(int	*n, int	*sign)
{
	int		digits;
	int		num;
	char	*str;

	digits = 0;
	if (*n < 0)
	{
		*sign = 1;
		*n = -*n;
	}
	num = *n;
	while (num > 0)
	{
		num = num / 10;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + *sign + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		ind;
	char	*str;

	sign = 0;
	ind = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_count_digit(&n, &sign);
	if (str == NULL)
		return (NULL);
	while (n > 0)
	{
		str[ind++] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign == 1)
		str[ind++] = '-';
	str[ind] = '\0';
	return (ft_strrev(str, ind));
}

/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	i = argc;
	i = atoi(argv[1]);
	printf("Int = %d, str = %s\n", i, ft_itoa(i));
}
*/
