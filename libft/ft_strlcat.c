/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:38:25 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 15:57:33 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;
	size_t	j;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	j = 0;
	if (dstsize <= lendst)
		return (dstsize + lensrc);
	while (dst[i])
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lendst + lensrc);
}

/*#include <string.h>
#include <stdio.h>
int	main (void)
{
	char dst[50] = "bonjour";
	char src[5] = "slt";
	prinft("%d", ft_strlcat(dst, src, 50));
	printf("%d", strlcat(dst, src, 50));
}*/
