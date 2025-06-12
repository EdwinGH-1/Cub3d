/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:40:21 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/10 10:31:41 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
	{
		arr = malloc(1);
		if (arr != NULL)
			return (arr);
		return (NULL);
	}
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}

/*
#include <stdio.h>
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size);

int main()
{
    // Test Case 1: Allocate an array of 5 integers
    int *arr1 = (int *)calloc(5, sizeof(int));

    if (arr1 == NULL)
    {
        printf("Allocation failed!\n");
        return 1;
    }

    // Verify that the allocated memory is initialized to 0
    printf("Test Case 1: Allocate 5 integers (initialized to 0)\n");
    for (size_t i = 0; i < 5; i++)
    {
        printf("arr1[%zu] = %d\n", i, arr1[i]);  // Should print 0 for all
    }
    free(arr1);  // Don't forget to free the allocated memory

    // Test Case 2: Allocate an array of 0 elements
    int *arr2 = (int *)calloc(0, sizeof(int));

    if (arr2 == NULL)
    {
        printf("Test Case 2: Allocation for 0 elem correctly return NULL\n");
    }
    else
    {
        printf("Test Case 2: Allocation for 0 elem failed (unexpected beh).\n");
        free(arr2);  // Free allocated memory if it somehow succeeded
    }

    // Test Case 3: Allocate a large array
    size_t large_size = 1000000;  // Large number of elements
    int *arr3 = (int *)calloc(large_size, sizeof(int));

    if (arr3 == NULL)
    {
        printf("Test Case 3: Allocation of large array failed.\n");
    }
    else
    {
        printf("Test Case 3: Large allocation %zu elements suc.\n", large_size);
        // We don't print all, but we can check that it's initialized to 0
        if (arr3[0] == 0)
        {
            printf("arr3[0] is correctly initialized to 0.\n");
        }
        free(arr3);  // Free large allocated memory
    }

    // Test Case 4: Test allocation failure
    size_t very_large_size = (size_t)-1;
    int *arr4 = (int *)calloc(very_large_size, sizeof(int));

    if (arr4 == NULL)
    {
        printf("Test Case 4: Allocation failed as expected.\n");
    }
    else
    {
        printf("Test Case 4: Allocation unexpectedly succeeded.\n");
        free(arr4);
    }

    return 0;
}
*/
