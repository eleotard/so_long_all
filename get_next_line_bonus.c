/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:36:12 by eleotard          #+#    #+#             */
/*   Updated: 2022/05/10 17:33:41 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*after_bs(char *s)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (s[i] != '\n')
		i++;
	i++;
	k = 0;
	while (s[k] != '\0')
		k++;
	tmp = malloc(sizeof(char) * (k - i + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while (s[i] != '\0')
	{
		tmp[j] = s[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*before_bs(char *s)
{
	int		i;
	int		j;
	char	*line;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (s[j] != '\n' && s[j] != '\0')
	{
		line[j] = s[j];
		j++;
	}
	if (s[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*setup_join(char *s1)
{
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (s1);
}

char	*read_until_nl(int fd, char *next_line)
{
	char	*buff;
	int		n_octets;

	n_octets = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	next_line = setup_join(next_line);
	while (!ft_parse(next_line) && n_octets != 0)
	{
		n_octets = read(fd, buff, BUFFER_SIZE);
		if (n_octets == -1)
		{
			next_line = ft_free(next_line, buff);
			return (NULL);
		}
		buff[n_octets] = '\0';
		next_line = ft_strjoin_g(next_line, buff);
	}
	free(buff);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	next_line = read_until_nl(fd, next_line);
	if (!next_line)
		return (NULL);
	if (next_line[0] == '\0')
	{
		next_line = ft_free(next_line, NULL);
		return (NULL);
	}
	line = before_bs(next_line);
	if (ft_strlen(next_line) == ft_strlen(line))
		next_line = ft_free(next_line, NULL);
	else if (ft_strlen(next_line) > ft_strlen(line))
	{
		tmp = after_bs(next_line);
		ft_free(next_line, NULL);
		next_line = ft_strdup(tmp);
		free(tmp);
	}
	return (line);
}
