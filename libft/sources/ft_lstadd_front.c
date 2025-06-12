/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:51:51 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 13:03:24 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>
#include <stddef.h>
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
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main()
{
    // Creating nodes
    int a = 10, b = 20;
    t_list *head = ft_lstnew(&a);  // First node
    t_list *new_node = ft_lstnew(&b);  // Second node

    // Adding a node to the front
    ft_lstadd_front(&head, new_node);

    // Add another node at the front
    int d = 40;
    t_list *new_node2 = ft_lstnew(&d);
    ft_lstadd_front(&head, new_node2);

    // Printing the list
    ft_lstprint(head);  // Expected Output: 40 -> 20 -> 10 -> NULL

    // Free allocated memory (not shown here, but important to do in practice)
    free(head); 
    free(new_node);
    free(new_node2);
    
    return 0;
}
*/
