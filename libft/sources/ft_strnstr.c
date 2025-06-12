/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:05:38 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 10:41:17 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
			{
				j++;
			}
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
    // Test case 1: Standard substring found
    char big1[] = "Hello, world!";
    char little1[] = "world";
    char *result1 = ft_strnstr(big1, little1, 12);
    if (result1)
        printf("Test1 pass: '%s' found at pos: %ld\n", result1, result1 - big1);
    else
        printf("Test 1 failed: substring not found.\n");

    // Test case 2: Substring not found
    char big2[] = "Hello, world!";
    char little2[] = "earth";
    char *result2 = ft_strnstr(big2, little2, 12);  // Search first 12 chars
    if (result2)
        printf("Test 2 failed: '%s' unexpectedly found.\n", result2);
    else
        printf("Test 2 passed: substring not found.\n");

    // Test case 3: Substring is empty
    char big3[] = "Hello, world!";
    char little3[] = "";
    char *result3 = ft_strnstr(big3, little3, 12);  // Empty substr ret big str
    if (result3)
        printf("Test 3 pass: empty substring, return big: '%s'\n", result3);
    else
        printf("Test 3 failed: empty substring not found.\n");

    // Test case 4: Substring larger than `len`
    char big4[] = "Hello, world!";
    char little4[] = "world";
    char *result4 = ft_strnstr(big4, little4, 5);  // ser 5 chars
    if (result4)
        printf("Test 4 failed: '%s' unexpectedly found.\n", result4);
    else
        printf("Test 4 passed: substring not found in first 5 characters.\n");

    // Test case 5: Substring at the beginning
    char big5[] = "Hello, world!";
    char little5[] = "Hello";
    char *result5 = ft_strnstr(big5, little5, 12);  // Search within 12 chars
    if (result5)
        printf("Test5 pass: '%s' found at pos: %ld\n", result5, result5 - big5);
    else
        printf("Test 5 failed: substring not found.\n");

    // Test case 6: Substring in the middle
    char big6[] = "The quick brown fox";
    char little6[] = "quick";
    char *result6 = ft_strnstr(big6, little6, 20);  // Search 20 chars
    if (result6)
        printf("Test6 pass: '%s' found at pos: %ld\n", result6, result6 - big6);
    else
        printf("Test 6 failed: substring not found.\n");

    // Test case 7: Mess
    char big7[] = "aAabaCacacD";
    char little7[] = "aC";
    char *result7 = ft_strnstr(big7, little7, 200);  // Search 200 chars
    if (result7)
        printf("Test7 pass: '%s' found at pos: %ld\n", result7, result7 - big7);
    else
        printf("Test 7 failed: substring not found.\n");
    return 0;
}
*/
