/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:13:48 by jthiew            #+#    #+#             */
/*   Updated: 2025/01/04 14:15:47 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_width(int width, int len, int zero)
{
	int	count;

	count = 0;
	while (width > len)
	{
		if (zero == 1)
			count += ft_print_char('0');
		if (zero == 0)
			count += ft_print_char(' ');
		width--;
	}
	return (count);
}
