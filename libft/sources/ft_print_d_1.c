/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:21:24 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/04 09:29:07 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_d_itoa(int d)
{
	int		nbr;
	char	*str;

	nbr = d;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			str = ft_strdup("2147483648");
			return (str);
		}
		else
			nbr *= -1;
	}
	str = ft_itoa(nbr);
	return (str);
}
