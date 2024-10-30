/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoumill <ssoumill@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:37:02 by ssoumill          #+#    #+#             */
/*   Updated: 2024/08/17 15:07:16 by ssoumill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_set_line(char *line)
{
	size_t	i;

	i = 0;
	if (line == NULL)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (i == ft_strlen_gnl(line))
		return (NULL);
	return (ft_substr_gnl(line, i + 1, ft_strlen_gnl(line) - i));
}

static char	*_fill_line(int fd, char *stock)
{
	size_t	read_count;
	char	*buffer;

	read_count = 1;
	while (ft_strchr_gnl(stock, '\n') == NULL)
	{
		if (read_count <= 0)
			break ;
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (ft_free(&stock), NULL);
		read_count = read(fd, buffer, BUFFER_SIZE);
		buffer[read_count] = '\0';
		stock = ft_strjoin_gnl(stock, buffer);
		ft_free(&buffer);
	}
	return (stock);
}

char	*ft_realline(char *lili)
{
	size_t	i;

	i = 0;
	if (lili == NULL)
		return (NULL);
	if (lili[0] == '\0')
		return (NULL);
	while (lili[i] != '\n' && lili[i] != '\0')
		i++;
	if (lili[i] == '\n')
		i++;
	return (ft_substr_gnl(lili, 0, i));
}

void	ft_free(char **buffer)
{
	if (buffer != NULL && *buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*result;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE >= INT_MAX)
		return (ft_free(&stock), NULL);
	if (!stock)
	{
		stock = malloc(1);
		if (!stock)
			return (NULL);
		stock[0] = '\0';
	}
	line = _fill_line(fd, stock);
	result = ft_realline(line);
	stock = _set_line(line);
	if (!ft_strchr_gnl(result, '\n') && line)
		ft_free(&stock);
	if (line)
		ft_free(&line);
	return (result);
}
