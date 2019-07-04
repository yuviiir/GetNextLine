/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 07:07:26 by ysharma           #+#    #+#             */
/*   Updated: 2019/06/26 06:58:52 by ysharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (count);
}

static int	ft_wordlen(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i++] != '\0')
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 0;
	count = 0;
	if (!s || !(str = (char **)malloc(sizeof(char*)
									* (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (i < ft_wordcount(s, c))
	{
		if (!(str[i] = (char*)malloc(sizeof(char)
										* (ft_wordlen(&s[count], c) + 1))))
			return (NULL);
		j = 0;
		while (s[count] == c)
			count++;
		while (s[count] != c && s[count] != '\0')
			str[i][j++] = s[count++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}
