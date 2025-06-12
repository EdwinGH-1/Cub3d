/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:35:07 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/04 09:34:25 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_logic_p(char *nbr_str, int nbr_len, int caps, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
	{
		count += ft_print_x_hash(caps, flags);
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
		count += ft_print_x_hash(caps, flags);
		count += ft_pad_width(flags.precision, nbr_len, 1);
		ft_putstr_fd(nbr_str, 1);
	}
	return (count);
}

int	ft_print_x_logic(char *nbr_str, int nbr_len, int caps, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_print_x_logic_p(nbr_str, nbr_len, caps, flags);
	else if (flags.zero == 1)
	{
		count += ft_print_x_hash(caps, flags);
		count += ft_pad_width(flags.width, nbr_len, 1);
		ft_putstr_fd(nbr_str, 1);
	}
	else
	{
		if (flags.left == 0)
			count += ft_pad_width(flags.width, nbr_len, 0);
		count += ft_print_x_hash(caps, flags);
		ft_putstr_fd(nbr_str, 1);
		if (flags.left == 1)
			count += ft_pad_width(flags.width, nbr_len, 0);
	}
	return (count + nbr_len);
}

void	ft_print_x_fmt_flags(int nbr_len, unsigned int d, t_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	if (d == 0)
		flags->hash = 0;
	if (flags->hash == 1)
		flags->width -= 2;
	if (flags->precision >= 0 || flags->left == 1)
		flags->zero = 0;
	if (flags->precision >= 0 && flags->precision < nbr_len)
		flags->precision = nbr_len;
}

int	ft_print_x(unsigned int d, int caps, t_flags flags)
{
	int		count;
	char	*nbr_str;

	count = 0;
	if (flags.precision == 0 && d == 0)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	nbr_str = ft_print_x_xtoa(d, caps);
	if (!nbr_str)
		return (0);
	ft_print_x_fmt_flags((int)ft_strlen(nbr_str), d, &flags);
	count += ft_print_x_logic(nbr_str, (int)ft_strlen(nbr_str), caps, flags);
	free(nbr_str);
	return (count);
}
