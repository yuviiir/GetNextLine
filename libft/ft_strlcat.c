/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:41:43 by ysharma           #+#    #+#             */
/*   Updated: 2019/06/10 06:55:11 by ysharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	result;

	len = 0;
	i = 0;
	while (dst[len] != '\0')
		len++;
	result = 0;
	while (src[result] != '\0')
		result++;
	if (dstsize <= len)
		result = result + dstsize;
	else
		result = result + len;
	i = 0;
	while (src[i] != '\0' && len + 1 < dstsize)
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	dst[len] = '\0';
	return (result);
}
