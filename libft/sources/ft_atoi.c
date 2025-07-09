/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jothomas <jothomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:51:40 by jthiew            #+#    #+#             */
/*   Updated: 2025/06/18 10:48:59 by jothomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - 48);
		nptr++;
	}
	return (result * sign);
}

static int	char_to_value(char c, int base_len)
{
	int		i;
	char	*base;

	base = "0123456789abcdef";
	c = ft_tolower(c);
	i = 0;
	while (base[i] && i < base_len)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	validate_str(const char *nptr, int base, int *parity)
{
	int	n;

	*parity = 1;
	n = 0;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == 32)
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			*parity *= -1;
		n++;
	}
	if (base == 16 && nptr[n] == '0' && (ft_tolower(nptr[n + 1]) == 'x'))
		n += 2;
	else if (base == 2 && nptr[n] == '0' && (ft_tolower(nptr[n + 1]) == 'b'))
		n += 2;
	return (n);
}

int	ft_atoi_base(const char *nptr, int base)
{
	int	n;
	int	parity;
	int	value;
	int	num;

	num = 0;
	if (!nptr || base < 2 || base > 16)
		return (0);
	n = validate_str(nptr, base, &parity);
	while (nptr[n])
	{
		num *= base;
		value = char_to_value(nptr[n], base);
		if (value == -1)
			break ;
		num += value;
		n++;
	}
	return (num * parity);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	//test 1
    char str1[] = "\n    01a23";
    int num1 = ft_atoi(str1);
    printf("num1 = %d, expect %d\n", num1, atoi(str1));

	//test 2
    char str2[] = "\n    -0123";
    int num2 = ft_atoi(str2);
    printf("num2 = %d, expect %d\n", num2, atoi(str2));

	//test 3
    char str3[] = "\n ";
    int num3 = ft_atoi(str3);
    printf("num3 = %d, expect %d\n", num3, atoi(str3));

	//test 4
    char str4[] = " +-3213";
    int num4 = ft_atoi(str4);
    printf("num4 = %d, expect %d\n", num4, atoi(str4));

    return 0;
}
*/
