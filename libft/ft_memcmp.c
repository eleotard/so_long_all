/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:11:10 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:18:09 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int	main (void)
{
	unsigned char	s1[] = "vraiestfaux";
	unsigned char 	s2[] = "vraie12345";
	unsigned char	s3[] = "vraiestfaux";
	unsigned char 	s4[] = "vraiest-2345";


	size_t	n = 15;

	printf("%d, %d\n", ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
    printf("%d, %d\n", ft_memcmp(s3, s4, n), memcmp(s3, s4, n));
	return (0);
}*/
