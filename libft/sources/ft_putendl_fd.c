/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:14:37 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/18 08:45:53 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(const char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write (fd, &*s, 1);
		s++;
	}
	write (fd, "\n", 1);
}

/*
int	main(int argc, char *argv[])
{
	int	i = argc;
	i = 2;
	ft_putendl_fd(argv[1], i);
}
*/
