/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghkim <atlanboa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:54:36 by sanghkim          #+#    #+#             */
/*   Updated: 2021/01/16 03:10:59 by sanghkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strndup(char *str, size_t n)
{
	char			*result;
	size_t			idx;

	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	idx = 0;
	while (idx < n)
	{
		result[idx] = str[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*cur;

	cur = (char *)s;
	while (*cur != c)
	{
		if (*cur == 0)
			return (NULL);
		cur++;
	}
	return (cur);
}

char   *ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	index_res;
	size_t	index_s;
	char	*res;

	if (s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	index_res = 0;
	if ((res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char))) == NULL)
		return (NULL);
	index_s = 0;
	while (s1 != NULL && index_s < len_s1)
		*(res + index_res++) = *(s1 + index_s++);
	index_s = 0;
	while (index_s < len_s2)
		*(res + index_res++) = *(s2 + index_s++);
	*(res + index_res) = '\0';
	return (res);
}
