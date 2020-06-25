/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:09:38 by msaubin           #+#    #+#             */
/*   Updated: 2018/12/03 22:12:38 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **start_list, t_list *new)
{
	t_list	*list;

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
