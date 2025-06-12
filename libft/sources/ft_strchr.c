/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:55:36 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/06 11:47:34 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (c == *s)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == *s)
	{
		return ((char *)s);
	}
	return (NULL);
}

/*
#include <stdio.h>
int main(void)
{
    const char *str = "Hello, World!";
	printf("String = %s\n", str);

    // Test 1: Character 'l' in the string
    const char *result = ft_strchr(str, 'l');
    if (result != NULL)
        printf("Test 1: Found 'l' at position: %ld\n", result - str);  // Pt ind
    else
        printf("Test 1: 'l' not found.\n");

    // Test 2: Character 'W' in the string
    result = ft_strchr(str, 'W');
    if (result != NULL)
       printf("Test 2: Found 'W' at position: %ld\n", result - str);  // Pt ind
    else
        printf("Test 2: 'W' not found.\n");

    // Test 3: Character 'z' not in the string
    result = ft_strchr(str, 'z');
    if (result != NULL)
        printf("Test 3: Found 'z' at position: %ld\n", result - str);
    else
        printf("Test 3: 'z' not found.\n");

    // Test 4: Search for the null terminator
    result = ft_strchr(str, '\0');
    if (result != NULL)
        printf("Test 4: Found null terminator at pos: %ld\n", result - str);

    return 0;
}
*/
