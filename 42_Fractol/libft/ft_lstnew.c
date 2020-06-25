/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:12:29 by msaubin           #+#    #+#             */
/*   Updated: 2019/04/28 14:28:27 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function create a new element and copy the content in it.
** If no content or no size is given the function set the content of the
** element to NULL and the content size to 0.
** Return: > the new element
**         > NULL if there is an error in memory allocation.
*/

t_list	*ft_lstnew(void const *ct, size_t size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (ct == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = (void*)malloc(sizeof(size))))
			return (NULL);
		ft_memcpy(new->content, ct, size);
		new->content_size = size;
	}
	new->next = NULL;
	return (new);
}
