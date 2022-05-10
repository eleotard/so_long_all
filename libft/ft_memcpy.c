/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:51:09 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 16:16:06 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dsttemp;
	unsigned char	*srctemp;

	dsttemp = (unsigned char *)dst;
	srctemp = (unsigned char *)src;
	if ((!dst) && (!src))
		return (0);
	i = 0;
	while (i < n)
	{
		*dsttemp = *srctemp;
		i++;
		dsttemp++;
		srctemp++;
	}
	return (dst);
}

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	if ((!dst) && (!src))
		return (0);	
	char    dest[100];
    
	printf("%s", ft_memcpy(dest, 'A', 4));
	printf("%s", memcpy())
}*/
