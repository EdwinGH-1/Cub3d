/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:12:03 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 10:02:09 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write (fd, &*s, 1);
		s++;
	}
}

/*
int	main(int argc, char *argv[])
{
	int	i = argc;
	i = 2;
	ft_putstr_fd(argv[1], i);
}
*/
