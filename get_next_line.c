/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:36:52 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/03 13:44:51 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * It reads from a file descriptor, and returns a line from it
 * 
 * @param fd file descriptor
 * 
 * @return A string containing the next line of the file.
 */
char	*get_next_line(int fd)
{
	char static	*buffer;
	char		*read_res;
	char		*result;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	read_res = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_res)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	result = ft_reader(fd, read_res, &buffer);
	free_str(&read_res);
	return (result);
}

/**
 * It reads from the file descriptor until it finds a newline character, and then returns the line
 * 
 * @param fd the file descriptor
 * @param read_res a buffer to store the read bytes
 * @param buffer This is the pointer to the pointer to the buffer.
 * 
 * @return a pointer to a string.
 */
char	*ft_reader(int fd, char *read_res, char **buffer)
{
	ssize_t	bytes_read;
	int		nl;
	char	*temp;

	bytes_read = 0;
	nl = ft_strchr(*buffer, '\n');
	while (!nl)
	{
		bytes_read = read(fd, read_res, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (append_line(nl, buffer));
		read_res[bytes_read] = 0;
		temp = ft_strjoin(*buffer, read_res);
		free_str(buffer);
		*buffer = temp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (append_line(nl, buffer));
}

/**
 * If the newline index is less than or equal to zero, then we return the entire buffer. Otherwise, we
 * return the buffer up to the newline index, and set the buffer to the remainder of the buffer
 * 
 * @param nl_index the index of the newline character in the buffer
 * @param buffer the buffer that contains the line
 * 
 * @return A pointer to a string.
 */
char	*append_line(int nl_index, char **buffer)
{
	char	*result;
	char	*temp;

	temp = NULL;
	if (nl_index <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		result = *buffer;
		*buffer = NULL;
		return (result);
	}
	temp = ft_substr(*buffer, nl_index, BUFFER_SIZE);
	result = *buffer;
	result[nl_index] = 0;
	*buffer = temp;
	return (result);
}

/**
 * > This function frees a string
 * 
 * @param ptr A pointer to a pointer to a char.
 */
void	free_str(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}
