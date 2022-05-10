/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:48:23 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 15:57:07 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static char	*ft_slcpy(char *d, char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			d[j] = s[i];
			j++;
		}	
		i++;
	}
	d[j] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		copy = malloc(sizeof(char));
		copy[0] = '\0';
		return (copy);
	}
	if (len > (ft_strlen(s) - start) + 1)
		copy = malloc(sizeof(*s) * (ft_strlen(s) - start) + 2);
	else
		copy = malloc(sizeof(*s) * len + 1);
	if (!copy)
		return (0);
	copy = ft_slcpy(copy, s, start, len);
	return (copy);
}

/*#include <stdio.h>
int	main(void)
{
	char	base[] = "hello world";
	printf("%s", ft_substr(base, 6, 5));
}*/
