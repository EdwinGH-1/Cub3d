/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:45:33 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/05 20:52:32 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
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

    printf("Testing ft_toupper function:\n");
    for (i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
    {
        char original = test_chars[i];
        char result = ft_toupper(original);

        printf("Original: '%c' -> ft_toupper: '%c'\n", original, result);
    }

    return 0;
}
*/
