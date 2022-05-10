/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:53:02 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 15:58:40 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*n_is_pos(int n, int len)
{
	char	*result;
	int		nb;

	nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}	
	result = malloc(sizeof(char) * len + 2);
	if (!result)
		return (0);
	result[len + 1] = '\0';
	while (len >= 0)
	{
		result[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (result);
}

char	*n_is_neg(int n, int len)
{
	char	*result;

	result = malloc(sizeof(char) * len + 3);
	if (!result)
		return (0);
	result[len + 2] = '\0';
	result[0] = '-';
	len++;
	while (len >= 1)
	{
		result[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*result;

	result = NULL;
	len = 0;
	nb = -n;
	if (n == -2147483648)
		result = ft_strdup("-2147483648");
	else if (n >= 0)
		result = n_is_pos(n, len);
	else if (n < 0)
	{
		while (nb > 9)
		{
			nb = nb / 10;
			len++;
		}
		result = n_is_neg(-n, len);
	}
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	int	n;

	n = 0;
	printf("%s", ft_itoa(n));
	return (0);
}*/
