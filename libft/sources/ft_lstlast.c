/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:12:18 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 13:21:57 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Helper function to create a new node (for testing purposes)
t_list *ft_lstnew(void *content)
{
    t_list *newNode = malloc(sizeof(t_list));
    if (newNode == NULL)
        return NULL;
    newNode->content = content;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the list (for testing purposes)
void ft_lstprint(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%d -> ", *(int *)lst->content);  // Assuming content is an int
        lst = lst->next;
    }
    printf("NULL\n");
}

// Test cases
int main()
{
    // Test 1: Empty list (should return NULL)
    t_list *head1 = NULL;
    t_list *last1 = ft_lstlast(head1);
    printf("Test 1: Empty list, last node: %p\n", last1); 

    // Test 2: Single node list
    int a = 10;
    t_list *head2 = ft_lstnew(&a);
    t_list *last2 = ft_lstlast(head2);
    printf("Test 2: Single, last node: %d\n", *(int *)last2->content);

    // Test 3: List with multiple nodes
    int b = 20, c = 30;
    t_list *head3 = ft_lstnew(&a);  // First node
    t_list *node2 = ft_lstnew(&b);  // Second node
    t_list *node3 = ft_lstnew(&c);  // Third node

    head3->next = node2;
    node2->next = node3;

    t_list *last3 = ft_lstlast(head3);
    printf("Test 3: Multiple, last node: %d\n", *(int *)last3->content);

    // Test 4: List with multiple nodes but malformed next pointer (edge case)
    t_list *head4 = ft_lstnew(&a);
    t_list *node4 = ft_lstnew(&b);
    head4->next = node4;
    node4->next = NULL;  // Valid, but we should check this case

    t_list *last4 = ft_lstlast(head4);
    printf("Test 4: List 2 node, last node: %d\n", *(int *)last4->content);

    // Test 5: List with circular reference (edge case)
    t_list *head5 = ft_lstnew(&a);
    t_list *node5 = ft_lstnew(&b);
    head5->next = node5;
    node5->next = head5;  // Circular list

    // If ft_lstlast is implemented correctly, 
	// it will loop indefinitely unless we fix the circular list
    // So we should expect it to handle non-circular cases. 
	// (Circular lists are outside the intended scope)
    t_list *last5 = ft_lstlast(head5);
    printf("Test 5: Cir. lst(undef), last node: %d\n", *(int *)last5->content);

    // Cleanup allocated memory (for non-circular cases)
    free(head2);
    free(node2);
    free(node3);
    free(head4);
    free(node4);
    free(head5);  
    free(node5);

    return 0;
}
*/
