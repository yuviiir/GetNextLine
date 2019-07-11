/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skynet <skynet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:39:20 by skynet            #+#    #+#             */
/*   Updated: 2019/07/11 09:52:02 by skynet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd(t_list **head, t_list *link)
{
	if (*head)
	{
		link->next = *head;
		link->prev = (*head)->prev;
		(*head)->prev = link;
	}
	*head = link;
	
}