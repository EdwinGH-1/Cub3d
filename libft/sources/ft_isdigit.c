/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:02:04 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 09:00:47 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	char *a[] = {"1", "9", "a", "b", "A", "Z", "-", "+"};
	int	i = 0;

	while (i < 8)
	{
		printf("%s is digit? %d\n", a[i], ft_isdigit(a[i][0]));
		i++;
	}
	return (0);
}
*/
