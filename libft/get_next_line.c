/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skynet <skynet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 07:38:25 by ysharma           #+#    #+#             */
/*   Updated: 2019/07/11 08:56:34 by skynet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dup_del(char **str, const int fd, char *temp, char **line)
{
	*line = ft_strdup(str[fd]);
	ft_strdel(&str[fd]);
	str[fd] = ft_strdup(temp);
	ft_strdel(&temp);
}

int		ft_read(char **str, const int fd, char *temp)
{
	char	buf[BUFF_SIZE + 1];
	int		i;

	if ((i = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	buf[i] = '\0';
	temp = ft_strjoin(str[fd], buf);
	ft_strdel(&str[fd]);
	str[fd] = ft_strdup(temp);
	ft_strdel(&temp);
	return (1);
}

int		ft_line(char **str, const int fd, char **line)
{
	*line = ft_strdup(str[fd]);
	ft_strclr(str[fd]);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*str[1024];
	char		*temp;
	char		*ptr;

	temp = NULL;
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!(str[fd]))
		str[fd] = ft_strnew(0);
	while ((ptr = ft_strchr(str[fd], '\n')) == NULL)
		if ((ft_read(str, fd, temp)) == 0)
			break ;
	if (ft_strlen(str[fd]) != 0)
	{
		if (!(ft_strchr(str[fd], '\n')))
			return (ft_line(str, fd, line));
		*ptr = '\0';
		temp = ft_strdup(ptr + 1);
		ft_dup_del(str, fd, temp, line);
	}
	else
		return (0);
	return (1);
}
