/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:03:32 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 14:06:45 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node
t_list *ft_lstnew(void *content) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Example function that prints an integer from the list
void print_int(void *content) {
    printf("%d ", *(int *)content);  // Print the integer
}

int main() {
    // Create a simple list with integers
    int a = 10, b = 20, c = 30;
    t_list *node1 = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    t_list *node3 = ft_lstnew(&c);

    node1->next = node2;
    node2->next = node3;

    // Apply ft_lstiter to print each element in the list
    ft_lstiter(node1, print_int);  // Expected output: 10 20 30

    return 0;
}
*/
