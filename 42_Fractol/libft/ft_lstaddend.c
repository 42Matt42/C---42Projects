/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:09:38 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 01:02:00 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function add an element at the end of the given linked list.
*/

void	ft_lstaddend(t_list **start_list, t_list *new)
{
	t_list	*list;

	if (!start_list || !new)
		return ;
	if (!*start_list)
		*start_list = new;
	else
	{
		list = *start_list;
		while (list->next)
			list = list->next;
		list->next = new;
	}
	return ;
}
