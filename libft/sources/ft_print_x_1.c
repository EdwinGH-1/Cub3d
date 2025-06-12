/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:16:47 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/04 09:32:04 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_hash(int caps, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.hash == 1)
	{
		if (caps == 0)
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		count += 2;
	}
	return (count);
}

char	*ft_print_x_str(unsigned int d, int len, int caps)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	len = 0;
	while (d > 0)
	{
		if (d % 16 >= 10)
		{
			if (caps == 0)
				str[len] = (d % 16) - 10 + 'a';
			else
				str[len] = (d % 16) - 10 + 'A';
		}
		else
			str[len] = (d % 16) + '0';
		len++;
		d /= 16;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_print_x_strrev(char *s, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
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

char	*ft_print_x_xtoa(unsigned int d, int caps)
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
		nbr /= 16;
	}
	str = ft_print_x_str(d, len, caps);
	if (!str)
		return (NULL);
	return (ft_print_x_strrev(str, len));
}
