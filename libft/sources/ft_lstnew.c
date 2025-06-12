/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:45:29 by jthiew            #+#    #+#             */
/*   Updated: 2025/03/07 17:42:08 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(int num, int ind)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

/*
#include <stdio.h>
int main()
{
    char *str = "Hello, world!";
    t_list *node = ft_lstnew(str);

    if (node != NULL)
    {
        printf("Node content: %s\n", (char *)node->content);
        printf("Next node: %p\n", node->next);
    }

    free(node);

    return 0;
}
*/
