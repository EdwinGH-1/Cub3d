/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:13 by jthiew            #+#    #+#             */
/*   Updated: 2024/11/09 13:47:33 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Example del function for an integer
void del(void *content)
{
    free(content);  // Assume content is an int, free it
}

int main()
{
    // Create a single node in the list
    t_list *node = malloc(sizeof(t_list));
    if (node == NULL) {
        return 1;  // Memory allocation failed
    }

    // Allocate memory for the content (an integer, for example)
    int *content = malloc(sizeof(int));
    if (content == NULL) {
        free(node);
        return 1;  // Memory allocation failed
    }

    *content = 42;  // Set the content to 42
    node->content = content;
    node->next = NULL;  // This node is the only node in the list

    // Now we delete the node using ft_lstdelone
    ft_lstdelone(node, del);  // The content (42) is freed, the node is freed

    return 0;
}
*/
