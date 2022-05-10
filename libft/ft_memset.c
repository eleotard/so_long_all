/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:47:11 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:15:03 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*#include <string.h>
#include <stdio.h>

		*t = c;
		i++;
		t++;
		
int	main(void)
{
	unsigned char	s[] = "abcdef";
	size_t			n;
	int				c;

	n = 4;
	c = 256;

	printf("%s\n", s);
	//printf("%d\n", c);
	//printf("%p\n", memset(s, c, n));
	ft_memset(s, c, n);
	printf("%s\n", s);
}*/
