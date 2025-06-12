/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:21:53 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/13 19:20:22 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//*dst = destination string
//*src = source string
//size = destination buffer size
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (!dst && size == 0)
		return (src_len);
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] != '\0' && (i + dest_len) < (size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
#include <stdio.h>
int	main(void)
{
	//test 1
	char dst1[12] = "Hello ";
	char src1[50] = "World!";
	size_t	size1 = 12;

	printf("Test 1\n");
	printf("Len of str tried to create: %zu\n", ft_strlcat(dst1, src1, size1));
	printf("Concatenated string: %s\n", dst1);

	printf("\n");

	//test 2
	char dst2[10] = "Hello ";
	char src2[50] = "World!";
	size_t	size2 = 10;

	printf("Test 2\n");
	printf("Len of str tried to create: %zu\n", ft_strlcat(dst2, src2, size2));
	printf("Concatenated string: %s\n", dst2);
	
	printf("\n");

	//test 3
	char dst3[15] = "rrrrrrrrrrrrrrr";
	char src3[50] = "lorem ipsum dolor sit amet";
	size_t	size3 = 5;

	printf("Test 3\n");
	printf("Len of str tried to create: %zu\n", ft_strlcat(dst3, src3, size3));
	printf("Concatenated string: %s", dst3);
	
	//test 4
	printf("Test 4\n");
	printf("Len of str tried to create: %d\n", strlcat(((void*)0), "nyan !", 0));
	//printf("Concatenated string: %s", dst3);

}
*/
