/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:26 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/04 09:29:04 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_sign(int d, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.plus == 1)
		count += ft_print_char('+');
	if (flags.space == 1)
		count += ft_print_char(' ');
	if (d < 0)
		count += ft_print_char('-');
	return (count);
}

int	ft_print_d_logic_pres(char *nbr_str, int nbr_len, int d, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
	{
		count += ft_print_d_sign(d, flags);
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
		count += ft_print_d_sign(d, flags);
		count += ft_pad_width(flags.precision, nbr_len, 1);
		ft_putstr_fd(nbr_str, 1);
	}
	return (count);
}

int	ft_print_d_logic(char *nbr_str, int nbr_len, int d, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_print_d_logic_pres(nbr_str, nbr_len, d, flags);
	else if (flags.zero == 1)
	{
		count += ft_print_d_sign(d, flags);
		count += ft_pad_width(flags.width, nbr_len, 1);
		ft_putstr_fd(nbr_str, 1);
	}
	else
	{
		if (flags.left == 0)
			count += ft_pad_width(flags.width, nbr_len, 0);
		count += ft_print_d_sign(d, flags);
		ft_putstr_fd(nbr_str, 1);
		if (flags.left == 1)
			count += ft_pad_width(flags.width, nbr_len, 0);
	}
	return (count + nbr_len);
}

void	ft_print_d_fmt_flags(int d, int nbr_len, t_flags *flags)
{
	if (d < 0)
	{
		flags->plus = 0;
		flags->space = 0;
	}
	if (flags->plus == 1)
		flags->space = 0;
	if (flags->precision >= 0 || flags->left == 1)
		flags->zero = 0;
	if (flags->precision >= 0 && flags->precision < nbr_len)
		flags->precision = nbr_len;
	if (d < 0 || flags->plus == 1 || flags->space == 1)
		flags->width--;
}

int	ft_print_d(int d, t_flags flags)
{
	int		count;
	char	*nbr_str;

	count = 0;
	if (flags.precision == 0 && d == 0)
	{
		if (flags.left == 1 && flags.plus == 1)
			count += ft_print_char('+');
		count += ft_pad_width(flags.width - flags.plus, 0, 0);
		if (flags.left == 0 && flags.plus == 1)
			count += ft_print_char('+');
		return (count);
	}
	nbr_str = ft_print_d_itoa(d);
	if (!nbr_str)
		return (0);
	ft_print_d_fmt_flags(d, (int)ft_strlen(nbr_str), &flags);
	count += ft_print_d_logic(nbr_str, (int)ft_strlen(nbr_str), d, flags);
	free(nbr_str);
	return (count);
}
