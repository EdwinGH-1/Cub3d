/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:46:43 by jthiew            #+#    #+#             */
/*   Updated: 2025/04/10 13:01:14 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (i == 0 && buffer[i] != '\n')
		return (NULL);
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = buffer[j];
		j++;
	}
	return (line);
}

static char	*ft_move_buffer(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = NULL;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (ft_strlen(buffer) + 1 - i == 1)
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(buffer) + 1 - i, sizeof(char));
	if (!temp)
		return (NULL);
	i = i + 1;
	while (buffer[i])
		temp[j++] = buffer[i++];
	free(buffer);
	return (temp);
}

static char	*ft_join(char *buffer, char *temp)
{
	char	*temp2;

	temp2 = ft_strjoin(buffer, temp);
	free(buffer);
	return (temp2);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*temp;
	int		size;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size <= 0)
			break ;
		temp[size] = '\0';
		buffer = ft_join(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	line = ft_get_line(buffer);
	buffer = ft_move_buffer(buffer);
	if (buffer != NULL && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd = open("./text.txt", O_RDONLY);
	char *s=get_next_line(fd);
	printf("%s\n", s);
	free(s);
}
*/
