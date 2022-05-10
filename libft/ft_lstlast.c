/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:37 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/11 15:58:30 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buff;

	if (!lst)
		return (lst);
	buff = lst;
	while (buff->next != NULL)
	{
		buff = buff->next;
	}
	return (buff);
}
