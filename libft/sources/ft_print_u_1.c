/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:23:25 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/04 09:26:34 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_u_strrev(char *s, int ind)
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

char	*ft_print_u_utoa(unsigned int d)
{
	unsigned int	nbr;
	int				len;
	char			*str;

	nbr = d;
	len = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	len = 0;
	while (d > 0)
	{
		str[len++] = (d % 10) + '0';
		d /= 10;
	}
	str[len] = '\0';
	str = ft_print_u_strrev(str, len);
	return (str);
}
