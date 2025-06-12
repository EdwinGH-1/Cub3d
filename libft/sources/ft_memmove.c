/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:33:39 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 10:12:19 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*psrc;
	char	*pdest;
	size_t	i;

	if (n == 0 || (dest == NULL && src == NULL))
		return (dest);
	psrc = (char *)src;
	pdest = (char *)dest;
	if (psrc < pdest && (psrc + n) > pdest)
	{
		while (n > 0)
		{
			pdest[n - 1] = psrc[n - 1];
			n--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			pdest[i] = psrc[i];
	}
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	//test 1
	char src1[100] = "123456789";
	char dest1[100] = "abcdef";

	ft_memmove(dest1, src1, 5);
	printf("test 1\n");
	printf("dest = %s\n", dest1);
	
	//test 2
	char src2[100] = "123456789";
	char *dest2 = src2;

	ft_memmove(dest2+2, src2, 5);
	printf("\n");
	printf("test2\n");
	printf("dest = %s\n", dest2);
}
*/
