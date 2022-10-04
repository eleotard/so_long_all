/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:43:58 by eleotard          #+#    #+#             */
/*   Updated: 2022/09/05 14:21:50 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_s(char *base, char *read)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!base || !read)
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen(base) + ft_strlen(read) + 2));
	if (!line)
		return (NULL);
	while (base[i])
	{
		line[i] = base[i];
		i++;
	}
	while (read[j])
	{
		line[i] = read[j];
		i++;
		j++;
	}
	line[i] = '\0';
	free(base);
	return (line);
}

char	*join(char *base, char *read)
{
	char	*new_read;

	if (!read)
	{
		read = malloc(sizeof(char));
		if (!read)
			return (free(base), NULL);
		read[0] = '\0';
	}
	new_read = ft_strjoin_s(base, read);
	if (!new_read)
		return (free(read), free(base), NULL);
	free(read);
	return (new_read);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
