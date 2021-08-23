/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:51:18 by jgainza-          #+#    #+#             */
/*   Updated: 2021/06/09 14:51:20 by jgainza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*ptr;

	while (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		ptr = (char *)malloc(sizeof(char *) * (len1 + len2 + 1));
		if (ptr == 0)
			return (0);
		i = -1;
		while (s1[++i])
			ptr[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			ptr[len1] = s2[i];
			len1++;
		}
		ptr[len1] = '\0';
		return (ptr);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	length;
	size_t	index;

	if (!(s))
		return (0);
	length = ft_strlen(s);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	index = 0;
	while (index < len && index + start < length)
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char			*s2;
	size_t			l;
	unsigned int	i;

	i = 0;
	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	if (s2)
	{
		while (s1 != '\0' && i < l)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		return (0);
	return (s2);
}
