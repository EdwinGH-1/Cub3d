/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:24:45 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/04 09:26:40 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u_logic_pres(char *nbr_str, int nbr_len, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
	{
		count += ft_pad_width(flags.precision, nbr_len, 1);
		ft_putstr_fd(nbr_str, 1);
		if (flags.precision > nbr_len)
			count += ft_pad_width(flags.width, flags.precision, 0);
		else
			count += ft_pad_width(flags.width, nbr_len, 0);
	}
	else
	{
		if (flags.precision > nbr_len)
			count += ft_pad_width(flags.width, flags.precision, 0);
		else
			count += ft_pad_width(flags.width, nbr_len, 0);
		count += ft_pad_width(flags.precision, nbr_len, 1);
		ft_putstr_fd(nbr_str, 1);
	}
	return (count);
}

int	ft_print_u_logic(char *nbr_str, int nbr_len, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_print_u_logic_pres(nbr_str, nbr_len, flags);
	else if (flags.zero == 1)
	{
		count += ft_pad_width(flags.width, nbr_len, 1);
		ft_putstr_fd(nbr_str, 1);
	}
	else
	{
		if (flags.left == 0)
			count += ft_pad_width(flags.width, nbr_len, 0);
		ft_putstr_fd(nbr_str, 1);
		if (flags.left == 1)
			count += ft_pad_width(flags.width, nbr_len, 0);
	}
	return (count + nbr_len);
}

void	ft_print_u_fmt_flags(int nbr_len, t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	if (flags->precision >= 0 || flags->left == 1)
		flags->zero = 0;
	if (flags->precision >= 0 && flags->precision < nbr_len)
		flags->precision = nbr_len;
}

int	ft_print_u(unsigned int d, t_flags flags)
{
	int		count;
	char	*nbr_str;

	count = 0;
	if (flags.precision == 0 && d == 0)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	nbr_str = ft_print_u_utoa(d);
	if (!nbr_str)
		return (0);
	ft_print_u_fmt_flags((int)ft_strlen(nbr_str), &flags);
	count += ft_print_u_logic(nbr_str, (int)ft_strlen(nbr_str), flags);
	free(nbr_str);
	return (count);
}
