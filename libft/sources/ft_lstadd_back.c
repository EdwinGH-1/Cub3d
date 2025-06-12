/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:22:09 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 13:29:55 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
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

int main()
{
    // Create an empty list
    t_list *head = NULL;

    // Add some nodes to the list
    int a = 10, b = 20, c = 30;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    ft_lstadd_back(&head, node1);  // Add first node
    ft_lstadd_back(&head, node2);  // Add second node
    ft_lstadd_back(&head, node3);  // Add third node

    // Print the list to verify the correct order
    ft_lstprint(head);  // Expected output: 10 -> 20 -> 30 -> NULL

    // Free allocated memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/
