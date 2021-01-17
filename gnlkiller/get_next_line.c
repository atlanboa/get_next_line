/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghkim <atlanboa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 04:27:30 by sanghkim          #+#    #+#             */
/*   Updated: 2021/01/16 03:43:11 by sanghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_ret_value(char **buf, char **line, char *nl_ptr)
{
	char	*tmp;

	if (nl_ptr)
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
	char			buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				idx;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	if (!fd_buf[fd])
		fd_buf[fd] = ft_strndup("", 1);
	while (!(ptr = ft_strchr(fd_buf[fd], '\n'))
	&& (idx = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[idx] = '\0';
		if (ptr)
			free(ptr);
		ptr = fd_buf[fd] ? ft_strjoin(fd_buf[fd], buf) : ft_strndup(buf, idx);
		if (fd_buf[fd])
			free(fd_buf[fd]);
		fd_buf[fd] = ptr;
	}
	return (idx < 0 ? ERROR : get_ret_value(&fd_buf[fd], line, ptr));
}

// int		main(int argc, char **argv)
// {
// 	char	*line;
// 	int		ret;
// 	int		fd;

// 	if (argc == 0)
// 		return(0);
// //	fd = 0;

// 	fd = open(argv[1], O_RDONLY);

// 	// while ((ret = get_next_line(fd, &line)))
// 	// {
// 	// 	printf("%s", line);
// 	// 	if (line)
// 	// 		free(line);
// 	// }
// 	int fd2 = open(argv[2], O_RDONLY);
// 	int fd3 = open(argv[3], O_RDONLY);

// 	ret = get_next_line(fd, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd2, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd2, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd2, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);


// 	ret = get_next_line(fd3, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd3, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	ret = get_next_line(fd3, &line);
// 	printf("get_next_line : %s\n", line);
// 	printf("return value : %d\n\n", ret);
// 	free(line);

// 	// ret = get_next_line(fd2, &line);
// 	// printf("get_next_line : %s\n", line);
// 	// printf("return value : %d\n\n", ret);
// 	// free(line);

// 	// ret = get_next_line(fd3, &line);
// 	// printf("get_next_line : %s\n", line);
// 	// printf("return value : %d\n\n", ret);
// 	// free(line);

// 	// ret = get_next_line(fd, &line);
// 	// printf("get_next_line : %s\n", line);
// 	// printf("return value : %d\n\n", ret);
// 	// free(line);

// 	// ret = get_next_line(fd2, &line);
// 	// printf("get_next_line : %s\n", line);
// 	// printf("return value : %d\n\n", ret);
// 	// free(line);

// 	// ret = get_next_line(fd3, &line);
// 	// printf("get_next_line : %s\n", line);
// 	// printf("return value : %d\n\n", ret);
// 	// free(line);

// 	// ret = get_next_line(fd, &line);
// 	// printf("get_next_line : %s\n", line);
// 	// printf("return value : %d\n", ret);
// 	// free(line);

// 	// ret = get_next_line(fd, &line);
// 	// printf("get_next_line : %s\n", line);
// 	// printf("return value : %d\n", ret);
// 	// free(line);
// }
