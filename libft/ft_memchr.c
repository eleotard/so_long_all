/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:06:11 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:17:58 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (t[i] == (unsigned char)c)
			return (t + i);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
    int s[] = {0, 1, 2 ,3 ,4 ,55555};
    int    c = 55555; 
    size_t  n = 1;

    printf("[%s]\n", memchr(s, c, n));
    printf("[%s]", ft_memchr(s, c, n));
}*/
