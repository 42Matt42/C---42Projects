/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:12:29 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/04 18:48:02 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a "fresh" link. 
// The variables content and content_size of the new link are initialized by
// copy of the parameters of the function.
// The variable next is initialized to NULL. 

#include "libft.h"

t_list	*ft_lstnew(void const *ct, size_t size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);

	// If the parameter content is nul, the variable content is initialized 
	// to NULL and the variable content_size is initialized to 0
	if (ct == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(sizeof(void*) * size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, ct, size);
		new->content_size = size;
	}
	new->next = NULL;
	return (new);
}
