/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:58:29 by eleotard          #+#    #+#             */
/*   Updated: 2021/11/26 14:02:47 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}
/*#include <stdio.h>
int	main(int argc, char **argv)
{
	(void)argc;
	if (ft_isdigit(argv[1][0]))
	       printf("est digit");
	else
		printf("pas digit");
}*/
