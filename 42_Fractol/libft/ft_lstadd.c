/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:12:26 by msaubin           #+#    #+#             */
/*   Updated: 2019/05/09 01:01:30 by msaubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function add an element at the beginning of the given linked list.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !*alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
