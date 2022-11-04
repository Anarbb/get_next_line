/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:31:01 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/03 13:43:41 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * It returns the index of the first occurrence of the character n in the string str, or 0 if n is not
 * found in str
 * 
 * @param str The string to search through.
 * @param n the character to find
 * 
 * @return The index of the first occurence of the character n in the string str.
 */
int	ft_strchr(char *str, char n)
{
	int	i;

	i = 0;
	while (str[i] != n)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (i + 1);
}

/**
 * It returns the length of a string.
 * 
 * @param str The string to be measured.
 * 
 * @return The length of the string.
 */
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * It allocates memory for a copy of the string str, copies the string into the allocated memory, and
 * returns a pointer to it
 * 
 * @param str The string to be copied.
 * 
 * @return A pointer to a newly allocated space in memory, which contains a copy of the string given as
 * a parameter.
 */
char	*ft_strdup(char *str)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen(str) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = str[i];
	return (s);
}

/**
 * It takes a string, a starting index, and a length, and returns a new string that is a substring of
 * the original string, starting at the given index and going for the given length
 * 
 * @param s The string to be split.
 * @param start the index of the first character to include in the substring.
 * @param len the maximum number of characters to copy
 * 
 * @return A pointer to a new string.
 */
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		return (ft_strdup(""));
	if (start + len > srclen)
		len = srclen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * It takes two strings and returns a new string that is the concatenation of the two strings
 * 
 * @param s1 The first string to be joined.
 * @param s2 the string to be appended to s1
 * 
 * @return A pointer to a string.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
