/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:15:11 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/03 14:25:35 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.left = 0;
	flags.zero = 0;
	flags.precision = -1;
	flags.star = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.width = 0;
	flags.spec = 0;
	return (flags);
}

t_flags	ft_flag_left(t_flags flags)
{
	flags.left = 1;
	flags.zero = 0;
	return (flags);
}

int	ft_flag_precision(const char *str, int i, va_list args, t_flags *flags)
{
	i = i + 1;
	if (str[i] == '*')
	{
		flags->precision = va_arg(args, int);
		return (i + 1);
	}
	flags->precision = 0;
	while (ft_isdigit(str[i]))
	{
		flags->precision = (flags->precision * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

t_flags	ft_flag_width(t_flags flags, va_list args)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.left = 1;
		flags.width *= -1;
	}
	return (flags);
}

void	ft_flag_digit(char c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - '0');
}
