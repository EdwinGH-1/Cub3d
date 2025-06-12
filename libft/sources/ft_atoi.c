/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:51:40 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/06 13:39:06 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
