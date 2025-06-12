/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:47:46 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 14:03:15 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Example del function for an integer (to delete the content)
void del(void *content)
{
    free(content);  // Free the content (which is dynamically allocated)
}

// Helper function to create a new node with integer content
t_list *ft_lstnew(void *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print the list (for testing purposes)
void ft_lstprint(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%d -> ", *(int *)lst->content);  // Print content of each node
        lst = lst->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create a simple linked list with three nodes
    t_list *head = ft_lstnew(malloc(sizeof(int)));
    *(int *)head->content = 10;

    t_list *node2 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node2->content = 20;
    head->next = node2;

    t_list *node3 = ft_lstnew(malloc(sizeof(int)));
    *(int *)node3->content = 30;
    node2->next = node3;

    // Print the list before clearing
    printf("Before clearing: ");
    ft_lstprint(head);

    // Clear the list
    ft_lstclear(&head, del);

    // Print the list after clearing (should be NULL)
    printf("After clearing: ");
    ft_lstprint(head);  // Should print "NULL"

    return 0;
}
*/
