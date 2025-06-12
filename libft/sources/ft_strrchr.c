/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:22:12 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/06 11:48:54 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	while (s[i] != '\0')
	{
		if (c == s[i])
		{
			index = i;
		}
		i++;
	}
	if (c == s[i])
	{
		return ((char *)(s + i));
	}
	else if (index == -1)
	{
		return (NULL);
	}
	else
	{
		return ((char *)(s + index));
	}
}

/*
#include <stdio.h>
int main(void)
{
    const char *str = "Hello, World!";
	printf("String= %s\n", str);

    // Test 1: Character 'l' (last occurrence)
    const char *result = ft_strrchr(str, 'l');
    if (result != NULL)
        printf("Test 1: Found 'l' at position: %ld\n", result - str);
    else
        printf("Test 1: 'l' not found.\n");

    // Test 2: Character 'o' (last occurrence)
    result = ft_strrchr(str, 'o');
    if (result != NULL)
        printf("Test 2: Found 'o' at position: %ld\n", result - str);
    else
        printf("Test 2: 'o' not found.\n");

    // Test 3: Character 'z' (not in string)
    result = ft_strrchr(str, 'z');
    if (result != NULL)
        printf("Test 3: Found 'z' at position: %ld\n", result - str);
    else
        printf("Test 3: 'z' not found.\n");

    // Test 4: Character ',' (found at the beginning)
    result = ft_strrchr(str, ',');
    if (result != NULL)
        printf("Test 4: Found ',' at position: %ld\n", result - str);
    else
        printf("Test 4: ',' not found.\n");

    // Test 5: Character '!' (last character in the string)
    result = ft_strrchr(str, '!');
    if (result != NULL)
        printf("Test 5: Found '!' at position: %ld\n", result - str);
    else
        printf("Test 5: '!' not found.\n");

    // Test 6: Search for the null terminator
    result = ft_strrchr(str, '\0');
    if (result != NULL)
        printf("Test 6: Found null terminator at pos: %ld\n", result - str);

    return 0;
}
*/
