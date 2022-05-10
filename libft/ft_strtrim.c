/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:44:32 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:20:59 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(const char	*set, char c)
{	
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	trim_start(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (is_inset(set, s[i]))
		i++;
	return (i);
}

static int	trim_end(char const *s, char const *set)
{
	int	j;

	j = 0;
	while (s[j])
		j++;
	j--;
	while (j >= 0 && is_inset(set, s[j]))
		j--;
	return (j);
}

char	*ft_copy(char *dest, const char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_copy;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = trim_start(s1, set);
	end = trim_end(s1, set);
	if (end >= start)
	{
		trim_copy = malloc(sizeof(char) * ((end - start) + 2));
		if (!trim_copy)
			return (0);
	}
	else
	{
		trim_copy = malloc(sizeof(char));
		*trim_copy = '\0';
		return (trim_copy);
	}
	trim_copy = ft_copy(trim_copy, s1, start, end);
	return (trim_copy);
}

/*#include <stdio.h>
int	main(void)
{
	char	s[] = " +  hello   + ";
	char	*set = " +";
	printf("%s", ft_strtrim(s, set));
}*/
