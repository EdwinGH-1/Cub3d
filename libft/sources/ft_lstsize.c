/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:04:49 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 13:12:08 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Helper function to create a new node (for testing purposes)
t_list *ft_lstnew(void *content)
{
    t_list *newnode = malloc(sizeof(t_list));
    if (newnode == NULL)
        return NULL;
    newnode->content = content;
    newnode->next = NULL;
    return newnode;
}

// Helper function to print the list (for testing purposes)
void ft_lstprint(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%d -> ", *(int *)lst->content); // Cast content to int&print
        lst = lst->next;
    }
    printf("NULL\n");
}

int main()
{
    // Test 1: Empty list
    t_list *head1 = NULL;
    printf("Size of empty list: %d\n", ft_lstsize(head1));  // Exp: 0

    // Test 2: List with one node
    int a = 10;
    t_list *head2 = ft_lstnew(&a);
    printf("Size of list with one node: %d\n", ft_lstsize(head2));  // Exp: 1

    // Test 3: List with multiple nodes
    int b = 20, c = 30;
    t_list *head3 = ft_lstnew(&a);  // First node
    t_list *node2 = ft_lstnew(&b);  // Second node
    t_list *node3 = ft_lstnew(&c);  // Third node

    head3->next = node2;
    node2->next = node3;

    printf("Size of list with three nodes: %d\n", ft_lstsize(head3));  // Exp:3

    // Clean up allocated memory
    free(head2);
    free(node2);
    free(node3);

    return 0;
}
*/
