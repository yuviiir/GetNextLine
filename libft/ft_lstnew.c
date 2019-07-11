/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skynet <skynet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:24:02 by skynet            #+#    #+#             */
/*   Updated: 2019/07/11 09:37:41 by skynet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, size_t size)
{
	t_list	*ret;

	ret = ft_memalloc(sizeof(t_list));
	ret->content = ft_memalloc(size);
	ft_memmove(ret->content, content, size);
	ret->next = NULL;
	ret->prev = NULL;
	return(ret);
}