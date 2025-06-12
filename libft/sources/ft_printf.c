/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:36:36 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/14 16:24:00 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/ft_printf.h"

int	ft_parse_flags(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[++i] != '\0')
	{
		if (str[i] == '-')
			*flags = ft_flag_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flags);
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_flag_width(*flags, args);
		if (ft_isdigit(str[i]))
			ft_flag_digit(str[i], flags);
		if (ft_strchr(SPECS, str[i]))
		{
			flags->spec = 1;
			break ;
		}
	}
	return (i);
}

int	ft_parse_specs(char c, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_print_c('%', flags);
	else if (c == 'c')
		count += ft_print_c(va_arg(args, int), flags);
	else if (c == 's')
		count += ft_print_s(va_arg(args, char *), flags);
	else if (c == 'p')
		count += ft_print_p((unsigned long)va_arg(args, void *), flags);
	else if (c == 'd' || c == 'i')
		count += ft_print_d(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_print_u(va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count += ft_print_x(va_arg(args, unsigned int), 0, flags);
	else if (c == 'X')
		count += ft_print_x(va_arg(args, unsigned int), 1, flags);
	return (count);
}

int	ft_parse_str(const char *str, va_list args)
{
	int		i;
	int		j;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (str[i])
	{
		flags = ft_init_flags();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			j = ft_parse_flags(str, i, args, &flags);
			if (flags.spec != 0)
				i = j;
			if (str[i] != '\0' && flags.spec > 0 && ft_strchr(SPECS, str[i]))
				count += ft_parse_specs(str[i], args, flags);
			else if (str[i] != '\0')
				count += ft_print_char(str[i]);
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;
	char	*str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	len = 0;
	va_start(args, format);
	len = ft_parse_str(str, args);
	va_end(args);
	free(str);
	return (len);
}
