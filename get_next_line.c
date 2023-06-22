/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:34:49 by aarranz-          #+#    #+#             */
/*   Updated: 2023/06/22 11:45:16 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_utils.c"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_detect(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || (s[i] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen_line(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' || (str[i] == '\0'))
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	strfree(char *buff, char *temp, char *line)
{
	buff = NULL;
	free(buff);
	temp = NULL;
	free(temp);
	line = NULL;
	free(line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*line;
	size_t			r;
	static char		*temp = "";

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	buff = malloc(sizeof(char) * (BUFFER_SIZE));
	while (temp)
	{
		r = read (fd, buff, BUFFER_SIZE);
		temp = ft_strjoin(temp, buff);
		if (ft_detect(temp) == 1 || r == 0)
		{
			line = ft_substr(temp, 0, ft_strlen_line(temp));
			temp = ft_strdup(ft_substr(temp, ft_strlen_line(temp), \
			ft_strlen(temp) - ft_strlen_line(temp)));
			strfree(buff, temp, line);
			return (line);
		}
	}
	strfree(buff, temp, line);
	return (NULL);
}

/* int	main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	close(fd);
} */
