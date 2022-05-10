/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:52:43 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/12 17:44:55 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	if (!s1)
		return (NULL);
	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
		return (0);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_parse(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_free(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (0);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	next_line = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!next_line)
		return (NULL);
	while (s1[i])
	{
		next_line[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		next_line[i] = s2[j];
		i++;
		j++;
	}
	next_line[i] = '\0';
	free(s1);
	return (next_line);
}
