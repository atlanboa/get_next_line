/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghkim <atlanboa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 04:27:30 by sanghkim          #+#    #+#             */
/*   Updated: 2021/01/17 22:28:15 by sanghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_ret_value(char **buf, char **line, char *nl_ptr, int idx)
{
	char	*tmp;

	if (idx < 0)
	{
		if (*buf)
			free(*buf);
		return (ERROR);
	}
	else if (nl_ptr)
	{
		*line = ft_strndup(*buf, nl_ptr - *buf);
		tmp = ft_strndup(nl_ptr + 1, ft_strlen(nl_ptr + 1));
		if (*buf)
			free(*buf);
		*buf = tmp;
		return (SUCCESS);
	}
	else if (*buf)
	{
		*line = *buf;
		*buf = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (SUCCESS_EOF);
}

int	get_next_line(int fd, char **line)
{
	static char		*fd_buf[OPEN_MAX];
	char			*buf;
	char			*ptr;
	int				idx;

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0
	|| !(buf = malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	if (!fd_buf[fd])
		fd_buf[fd] = ft_strndup("", 1);
	while (!(ptr = ft_strchr(fd_buf[fd], '\n'))
	&& (idx = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[idx] = '\0';
		ptr = ft_strjoin(fd_buf[fd], buf);
		if (fd_buf[fd])
			free(fd_buf[fd]);
		fd_buf[fd] = ptr;
	}
	if (buf)
		free(buf);
	return (get_ret_value(&fd_buf[fd], line, ptr, idx));
}
