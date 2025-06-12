/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:05:39 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/04 21:16:40 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

/*
#include <unistd.h>
int	main(void)
{
	char	a[13] = "Hello world!";
	for (int i = 0; i <= 13; i++)
	{
		write(1, &a[i], 1);
	}
	write(1, "\n", 1);
	ft_bzero(a, 5);
	for (int i = 0; i <= 13; i++)
	{
		write(1, &a[i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
*/
