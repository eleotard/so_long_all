/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:53:31 by eleotard          #+#    #+#             */
/*   Updated: 2021/11/25 13:53:31 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r'
		|| nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (sign * result);
}
/*#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	s[] = "---+++ 1543ab";
	char	r[] = "-2543ab";
	char	u[] = "3543ab";
	char	t[] = "gg3543ab";

	printf("%d\n", ft_atoi(s));
	printf("%d\n", ft_atoi(r));
	printf("%d\n", ft_atoi(u));
	printf("%d\n\n", ft_atoi(t));

	printf("%d\n", atoi(s));
	printf("%d\n", atoi(r));
	printf("%d\n", atoi(u));
	printf("%d\n\n", atoi(t));

	return (0);
}*/
