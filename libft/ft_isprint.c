/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:00:01 by eleotard          #+#    #+#             */
/*   Updated: 2021/11/26 14:02:48 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (!(c > 31 && c < 127))
		return (0);
	return (1);
}

/*#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int     numero;
	
	numero = 0;
        while (numero < 130)
        {
		printf("%d", numero);
		printf(" ");
		printf("%d\n", isprint(numero));
		printf("%d", numero);
		printf(" ");
		printf("%d\n", ft_isprint(numero));
		numero++;
        }
}*/
