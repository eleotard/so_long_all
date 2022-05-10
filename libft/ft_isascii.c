/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:14:17 by eleotard          #+#    #+#             */
/*   Updated: 2021/11/26 14:02:46 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	return (1);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	numero;
	
	numero = -30;
	while (numero < 300)
	{
		printf("%d", numero);
		printf(" ");
		printf("%d\n", isascii(numero));
		printf("%d", numero);
		printf(" ");
		printf("%d\n", ft_isascii(numero));
		numero++;
	}
}*/