/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:52:11 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 09:34:20 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
    const char str[] = "Hello, World!";
    char ch = 'o';
    size_t n = 13;  // Length of the string

	printf("String: %s\n", str);
    // Test 1: Find 'o' in the string
    const void *result = ft_memchr(str, ch, n);
    if (result) {
        printf("Found '%c' at position %ld\n", ch, (const char *)result - str);
    } else {
        printf("'%c' not found\n", ch);
    }

    // Test 2: Find a character that is not in the string
    ch = 'z';
    result = ft_memchr(str, ch, n);
    if (result) {
        printf("Found '%c' at position %ld\n", ch, (const char *)result - str);
    } else {
        printf("'%c' not found\n", ch);
    }

    // Test 3: Find the null terminator '\0'
    ch = '\0';
    result = ft_memchr(str, ch, n);
    if (result) {
        printf("Found '\\0' at position %ld\n", (const char *)result - str);
    } else {
        printf("Null terminator not found\n");
    }

    // Test 4: Find the 'W' in first 5 bytes
    ch = 'W';
	n = 5;
    result = ft_memchr(str, ch, n);
    if (result) {
        printf("Found '%c' at position %ld\n", ch, (const char *)result - str);
    } else {
        printf("'%c' not found in first %ld bytes\n", ch, n);
    }
    return 0;
}
*/
