/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 07:05:44 by ysharma           #+#    #+#             */
/*   Updated: 2019/06/10 06:49:52 by ysharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	if (s == NULL && !c && !n)
		return (NULL);
	i = 0;
	s2 = (unsigned char *)s;
	while (n > i)
	{
		if (s2[i] == (unsigned char)c)
			return (s2 + i);
		i++;
	}
	return (0);
}
