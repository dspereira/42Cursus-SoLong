/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilveri <dsilveri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:02:59 by diogo             #+#    #+#             */
/*   Updated: 2022/05/15 14:11:18 by dsilveri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0)
		return (0);
	line = 0;
	get_line(fd, &line);
	return (line);
}

void	get_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			status;
	int			nl_index;

	status = 1;
	nl_index = -1;
	while (status > 0 && nl_index < 0)
	{
		if (!ft_strlen(buff))
			status = read_file(fd, buff);
		nl_index = get_char(buff, '\n');
		if (status > 0 && nl_index < 0)
		{
			*line = line_cat(*line, buff, status);
			update_buffer(buff, (buff + status));
		}	
		else if (nl_index >= 0)
		{
			*line = line_cat(*line, buff, nl_index + 1);
			update_buffer(buff, (buff + nl_index + 1));
		}
	}
}

/*
return: 
		> 0  number of bytes read
		= 0  end of file
	    < 0  error
*/
int	read_file(int fd, char *buff)
{
	ft_bzero(buff, BUFFER_SIZE + 1);
	return (read(fd, buff, BUFFER_SIZE));
}

char	*line_cat(char *line, char *buff, int n)
{
	int		i;
	int		line_len;
	char	*new_line;

	if (!line)
		line_len = 0;
	else
		line_len = ft_strlen(line);
	new_line = malloc(line_len + n + 1 + sizeof(char));
	if (!new_line)
		return (0);
	if (line_len > 0)
	{
		ft_strlcpy(new_line, line, line_len + 1);
		free(line);
	}
	i = 0;
	while (i < n && buff[i] != '\0')
	{
		new_line[line_len + i] = buff[i];
		i++;
	}
	new_line[line_len + i] = '\0';
	return (new_line);
}

void	update_buffer(char *buff, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		buff[i] = src[i];
		i++;
	}
	buff[i] = '\0';
}
