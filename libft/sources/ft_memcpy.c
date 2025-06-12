/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:19:36 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 10:11:34 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	if (dest == NULL && src == NULL)
		return (dest);
	dptr = (unsigned char *)dest;
	sptr = (const unsigned char *)src;
	while (n > 0)
	{
		*dptr = *sptr;
		dptr++;
		sptr++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
    char src[] = "Hello, World!";
    char dest[50]; // Ensure enough space in destination

    // Copy data from src to dest
    ft_memcpy(dest, src, 13); // Copy 13 bytes (including the null terminator)

    // Null-terminate the destination string
    dest[13] = '\0'; // Ensure dest is null-terminated

    // Print the results
    printf("Source: %s\n", src);
    printf("Destination after memcpy: %s\n", dest); // Expected: "Hello, World!"

    return 0;
}
*/
