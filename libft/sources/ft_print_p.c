/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:17:40 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/03 16:25:28 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p_logic(unsigned long p, char *adr_str, int adr_len)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		ft_putstr_fd(adr_str, 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(adr_str, 1);
		return (adr_len + 2);
	}
}

char	*ft_print_p_strrev(char *s, int ind)
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

int	ft_print_p_adr_len(unsigned long p)
{
	int	len;

	len = 0;
	while (p > 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

char	*ft_print_p_adr_str(unsigned long p)
{
	char			*str;
	unsigned long	nbr;
	int				len;

	nbr = p;
	len = ft_print_p_adr_len(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	len = 0;
	while (nbr > 0)
	{
		if (nbr % 16 >= 10)
			str[len] = (nbr % 16) - 10 + 'a';
		else
			str[len] = (nbr % 16) + '0';
		len++;
		nbr /= 16;
	}
	str[len] = '\0';
	return (ft_print_p_strrev(str, len));
}

int	ft_print_p(unsigned long p, t_flags flags)
{
	int		count;
	char	*adr_str;

	count = 0;
	if (p == 0)
		adr_str = ft_strdup("(nil)");
	else
	{
		flags.width -= 2;
		adr_str = ft_print_p_adr_str(p);
	}
	if (!adr_str)
		return (0);
	if (flags.left == 1)
		count += ft_print_p_logic(p, adr_str, (int)ft_strlen(adr_str));
	count += ft_pad_width(flags.width, (int)ft_strlen(adr_str), 0);
	if (flags.left == 0)
		count += ft_print_p_logic(p, adr_str, (int)ft_strlen(adr_str));
	free(adr_str);
	return (count);
}
