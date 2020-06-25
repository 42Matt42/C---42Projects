/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:09:58 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 01:03:47 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function delete a linked list and free all the links and set it to NULL.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst || !del)
		return ;
	(*del)((*alst)->content, (*alst)->content_size);
	if ((*alst)->next)
		ft_lstdel(&(*alst)->next, del);
	free(*alst);
	(*alst) = NULL;
}
