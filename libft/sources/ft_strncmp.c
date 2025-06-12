/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:32:18 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 10:37:03 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//*s1 = string 1
//*s2 = string 2
//n = at most n bytes to compare

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0 || (ft_strlen(s1) == 0 && ft_strlen(s2) == 0))
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 > c2)
		{
			return (1);
		}
		if (c1 < c2)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>  // For comparison with the standard library

int main(void)
{
    // Test 1: Identical strings up to n bytes
    const char *str1 = "hello";
    const char *str2 = "hello";
    size_t n = 5;
	printf("Test 1\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str1, str2, n);
    printf("Comp = %d\n", ft_strncmp(str1, str2, n));

    // Test 2: First string is lexicographically greater
    const char *str3 = "hello";
    const char *str4 = "hella";
	printf("\nTest 2\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str3, str4, n);
    printf("Comp = %d\n", ft_strncmp(str3, str4, n));

    // Test 3: First string is lexicographically smaller
    const char *str5 = "hella";
    const char *str6 = "hello";
	printf("\nTest 3\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str5, str6, n);
    printf("Comp = %d\n", ft_strncmp(str5, str6, n));

    // Test 4: Comparing different length strings (first string shorter)
    const char *str7 = "hi";
    const char *str8 = "hello";
    n = 3;  // Compare up to 3 bytes
	printf("\nTest 4\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str7, str8, n);
    printf("Comp = %d\n", ft_strncmp(str7, str8, n));

    // Test 5: Comparing different length strings (second string shorter)
    const char *str9 = "hello";
    const char *str10 = "hi";
    n = 3;  // Compare up to 3 bytes
	printf("\nTest 5\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str9, str10, n);
    printf("Comp = %d\n", ft_strncmp(str9, str10, n));

    // Test 6: Comparing strs of different lens, n is greater than both lengths
    const char *str11 = "abc";
    const char *str12 = "abcd";
    n = 5;  // Compare up to 5 bytes (longer than either string)
	printf("\nTest 6\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str11, str12, n);
    printf("Comp = %d\n", ft_strncmp(str11, str12, n));

    // Test 7: Empty strings
    const char *str13 = "";
    const char *str14 = "";
    n = 3;  // Compare up to 3 bytes (empty strings)
	printf("\nTest 7\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str13, str14, n);
    printf("Comp = %d\n", ft_strncmp(str13, str14, n));

    // Test 8: Empty string and non-empty string
    const char *str15 = "";
    const char *str16 = "hello";
    n = 3;
	printf("\nTest 8\n");
	printf("s1 = %s, s2 = %s, n = %zu\n", str15, str16, n);
    printf("Comp = %d\n", ft_strncmp(str15, str16, n));

    // Test 9: Standard library comparison (for validation)
    const char *str17 = "apple";
    const char *str18 = "apple";
    n = 5;
    int result_lib = strncmp(str17, str18, n);
	printf("\nTest 9\n");
    printf("Cmp '%s' and '%s' w/ std strncmp: %d\n", str17, str18, result_lib);
    int result_custom = ft_strncmp(str17, str18, n);
    printf("Cmp '%s' and '%s' w/ ft_strncmp: %d\n", str17, str18, result_custom);

    return 0;
}
*/
