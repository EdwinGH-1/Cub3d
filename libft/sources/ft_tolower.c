/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:52:56 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/05 20:55:14 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

/*
#include <stdio.h>
int main(void)
{
    char test_chars[] = {'a', 'z', 'A', 'Z', '0', '!', ' ', '\n', 'b'};
    size_t i;

    printf("Testing ft_tolower function:\n");
    for (i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
    {
        char original = test_chars[i];
        char result = ft_tolower(original);

        printf("Original: '%c' -> ft_lower: '%c'\n", original, result);
    }

    return 0;
}
*/
