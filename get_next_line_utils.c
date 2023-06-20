/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:05 by aarranz-          #+#    #+#             */
/*   Updated: 2023/06/14 10:30:29 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	length;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	length = len;
	i = start;
	k = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) <= len)
		length = ft_strlen(s + start);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	while (length-- && s[i])
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;	

	i = 0;
	len = ft_strlen(s1);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s1[i];
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	size_t	len;
	size_t	i;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	k = 0;
	i = (ft_strlen(s1));
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str1 = malloc(sizeof(char) * (len));
	if (str1 == NULL || (str1 == NULL && s2 == NULL))
		return (NULL);
	ft_strlcpy(str1, s1, len);
	while (i <= len && s2[k])
	{
		str1[i] = s2[k];
		i++;
		k++;
	}
	str1[i] = '\0';
	return (str1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	if (dstsize == 0)
	{
		return (j);
	}
	i = 0;
	while (src[i] != '\0' && i < dstsize -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
