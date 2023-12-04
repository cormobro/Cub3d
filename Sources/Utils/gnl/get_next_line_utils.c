/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:16:42 by febonaer          #+#    #+#             */
/*   Updated: 2022/10/20 13:30:05 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/get_next_line.h"

char	*ft_strjoin(char *stack, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!stack)
	{
		stack = (char *)malloc(1 * sizeof(char));
		stack[0] = '\0';
	}
	if (!stack || !buffer)
		return (NULL);
	res = malloc(sizeof(char) * ((ft_strlen(stack) + ft_strlen(buffer)) + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stack)
		while (stack[++i] != '\0')
			res[i] = stack[i];
	while (buffer[j] != '\0')
		res[i++] = buffer[j++];
	res[ft_strlen(stack) + ft_strlen(buffer)] = '\0';
	free(stack);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (c > 256)
		c = c - 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (!c)
		return ((char *)&s[i]);
	return (0);
}
