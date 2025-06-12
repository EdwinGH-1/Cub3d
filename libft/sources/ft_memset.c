/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:55:12 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/04 21:05:23 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
int main(void)
{
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";

    ft_memset(str1, '*', 5);
    printf("Result: %s\n", str1);

    ft_memset(str2, '*', 0);
    printf("Result: %s\n", str2);

    return 0;
}
*/
