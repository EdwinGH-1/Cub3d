/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:34:07 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/06 12:00:15 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] > ptr2[i])
		{
			return (1);
		}
		if (ptr1[i] < ptr2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    // Test case 1: Compare two identical memory blocks
    char str1[] = "Hello";
    char str2[] = "Hello";
    int result = ft_memcmp(str1, str2, 5);
    printf("Test 1 res: %d (Expect: 0)\n", result); // Expect: 0 cuz identical

    // Test case 2: Compare two different memory blocks
    char str3[] = "Hello";
    char str4[] = "Hellp";
    result = ft_memcmp(str3, str4, 5);
    printf("Test 2 res: %d (Expect: -1)\n", result); // Expect: -1 cuz 'o' < 'p'

    // Test case 3: Compare memory blocks with different length
    char str5[] = "Hello";
    char str6[] = "Hell";
    result = ft_memcmp(str5, str6, 5);
    printf("Test 3 res: %d (Expect: 1)\n", result); // Expect: 1 cuz more char

    // Test case 4: Compare memory blocks with first non-matching byte at end
    char str7[] = "World";
    char str8[] = "Worldy";
    result = ft_memcmp(str7, str8, 6);
    printf("Test 4 res: %d (Expect: -1)\n", result); // Expect: -1 cuz 'd' < 'y'

    // Test case 5: Compare with n = 0 (edge case)
    result = ft_memcmp(str1, str2, 0);
    printf("Test 5 res: %d (Expect: 0)\n", result); // Expect: 0 cmp nothin

    return 0;
}
*/
