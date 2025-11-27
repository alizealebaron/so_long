/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:46:54 by alebaron          #+#    #+#             */
/*   Updated: 2025/11/25 09:12:45 by alebaron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*get_next_line(int fd);
static char	*get_a_line(int fd, char *buffer, char *storage);
static char	*join_and_free(char *s1, char *s2);
static char	*clean_line(char *next_line);
static void	update_storage(char *storage, char *next_line);

char	*get_next_line(int fd)
{
	static char	storage[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	next_line = get_a_line(fd, buffer, storage);
	update_storage(storage, next_line);
	next_line = clean_line(next_line);
	return (next_line);
}

static void	update_storage(char *storage, char *next_line)
{
	char	*tmp;
	size_t	i;

	tmp = ft_strchr(next_line, '\n');
	if (!tmp)
	{
		storage[0] = '\0';
		return ;
	}
	tmp++;
	i = 0;
	while (tmp[i] != '\0' && i < BUFFER_SIZE)
	{
		storage[i] = tmp[i];
		i++;
	}
	storage[i] = '\0';
}

static char	*clean_line(char *next_line)
{
	size_t	len;
	char	*tmp;

	if (!next_line)
		return (NULL);
	len = 0;
	while (next_line[len] != '\n' && next_line[len] != '\0')
		len++;
	if (next_line[len] == '\n')
	{
		tmp = ft_substr(next_line, 0, len + 1);
		free(next_line);
		return (tmp);
	}
	else
	{
		tmp = ft_substr(next_line, 0, len);
		free(next_line);
		return (tmp);
	}
}

static char	*get_a_line(int fd, char *buffer, char *storage)
{
	int		ret_read;
	char	*tmp;

	ret_read = 1;
	tmp = ft_strdup(storage);
	if (!tmp)
		return (NULL);
	while (ret_read != 0 && !ft_strchr(tmp, '\n'))
	{
		ret_read = read(fd, buffer, BUFFER_SIZE);
		if (ret_read < 0)
			return (NULL);
		else if (ret_read == 0)
			break ;
		buffer[ret_read] = '\0';
		tmp = join_and_free(tmp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret_read == 0 && (!tmp || !*tmp))
	{
		free(tmp);
		tmp = NULL;
	}
	return (tmp);
}

static char	*join_and_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("giant_line_nl.txt", O_RDONLY);
// 	line = "";

// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	free(line);
// 	fd = close(fd);
// 	return (0);
// }
