/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:22:10 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 09:47:45 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//*dst = destination buffer
//*src = source string
//size = size of dst buffer
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_cnt;
	size_t	i;

	s_cnt = 0;
	i = 0;
	while (src[s_cnt] != '\0')
		s_cnt++;
	if (size == 0)
		return (s_cnt);
	while (i < s_cnt && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_cnt);
}

/*
#include <stdio.h>
int main(void)
{
    char dst[20];  // A destination buffer large enough for testing
    const char *src1 = "Hello, World!";
    const char *src2 = "Short";
    const char *src3 = "A very long string that exceeds buffer size";

    size_t size;

    // Test 1: Copying a string that fits entirely within the buffer
    size = sizeof(dst);
    printf("Test 1: Copying \"%s\" with buffer size %zu\n", src1, size);
    ft_strlcpy(dst, src1, size);
    printf("Dest: '%s' | Source len: %zu\n", dst, ft_strlcpy(dst, src1, size));

    // Test 2: Copying a string with a smaller buffer, truncating the string
    size = 6;  // Only space for 5 char + null terminator
    printf("\nTest 2: Copying \"%s\" with buffer size %zu\n", src1, size);
    ft_strlcpy(dst, src1, size);
    printf("Dest: '%s' | Source len: %zu\n", dst, ft_strlcpy(dst, src1, size));

    // Test 3: Copying a shorter string into a large buffer
    size = 20;  // Large enough buffer
    printf("\nTest 3: Copying \"%s\" with buffer size %zu\n", src2, size);
    ft_strlcpy(dst, src2, size);
    printf("Dest: '%s' | Source len: %zu\n", dst, ft_strlcpy(dst, src2, size));

    // Test 4: Copying a long str with a smaller buffer, truncating the string
    size = 10;  // Only space for 9 characters + null terminator
    printf("\nTest 4: Copying \"%s\" with buffer size %zu\n", src3, size);
    ft_strlcpy(dst, src3, size);
    printf("Dest: '%s' | Source len: %zu\n", dst, ft_strlcpy(dst, src3, size));

    return 0;
}
*/
