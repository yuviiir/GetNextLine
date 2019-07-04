/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:41:37 by ysharma           #+#    #+#             */
/*   Updated: 2019/06/12 14:47:28 by ysharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb /= 10)
		len++;
	return (len + 1);
}

char		*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	nb;

	nb = n;
	len = ft_len(nb);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	str[len--] = '\0';
	while (nb > 0)
	{
		str[len--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}
