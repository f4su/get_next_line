/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:51:30 by jgainza-          #+#    #+#             */
/*   Updated: 2021/06/11 10:03:40 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_finish(char **ptr, char **line)
{
	if (ft_strchr(*ptr, '\0'))
	{
		*line = ft_strdup(*ptr);
		free(*ptr);
		*ptr = NULL;
		return (0);
	}
	return (0);
}

int	ft_nuller(ssize_t *reader, char **ptr)
{
	if (*reader < 0)
	{
		if (*ptr != NULL)
		{
			free(*ptr);
			*ptr = NULL;
		}
		return (-1);
	}
	return (0);
}

int	ft_gest_error(ssize_t reader, char **ptr, char **line)
{
	char	*temp;
	char	*temp2;

	if (!reader && !*ptr)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_nuller(&reader, &*ptr))
		return (-1);
	temp = ft_strchr(*ptr, '\n');
	if (temp)
	{
		*temp = '\0';
		*line = ft_strdup(*ptr);
		temp2 = ft_strdup(temp + 1);
		free(*ptr);
		*ptr = temp2;
		return (1);
	}
	else if (ft_finish(&*ptr, &*line))
		return (0);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*ptr[OPEN_MAX];
	ssize_t		reader;
	char		*temp;

	reader = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || !buffer || fd > OPEN_MAX)
		return (-1);
	while (reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		buffer[reader] = '\0';
		if (!ptr[fd])
			ptr[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(ptr[fd], buffer);
			free(ptr[fd]);
			ptr[fd] = temp;
		}
	}
	free(buffer);
	buffer = NULL;
	return (ft_gest_error(reader, &ptr[fd], &*line));
}
