/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleotard <eleotard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:48:55 by eleotard          #+#    #+#             */
/*   Updated: 2022/04/25 18:11:52 by eleotard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE	1

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_free(char *s1, char *s2);
int		ft_parse(char *s);

#endif
