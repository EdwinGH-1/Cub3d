/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:16:56 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/03 11:02:23 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string_pre(char *s, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		while (s[count] != '\0' && count < flags.precision)
		{
			ft_putchar_fd(s[count], 1);
			count++;
		}
		return (count);
	}
	else
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
}

// NULL str with prec & prec < 6 output nothing.
// if prec > strlen, print strlen
int	ft_print_s(char *s, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	if (s == NULL && flags.precision > -1 && flags.precision < 6)
	{
		count += ft_pad_width(flags.width, 0, 0);
		return (count);
	}
	if (s == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		count += ft_print_string_pre(str, flags);
	if (flags.precision >= 0)
		count += ft_pad_width(flags.width, flags.precision, 0);
	else
		count += ft_pad_width(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		count += ft_print_string_pre(str, flags);
	free(str);
	return (count);
}
