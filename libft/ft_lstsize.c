/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:07:49 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 15:58:20 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*buff;
	size_t	i;

	if (!lst)
		return (0);
	buff = lst;
	i = 0;
	while (buff)
	{
		buff = buff->next;
		i++;
	}
	return (i);
}
