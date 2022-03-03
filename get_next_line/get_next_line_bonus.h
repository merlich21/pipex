/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:17:22 by merlich           #+#    #+#             */
/*   Updated: 2022/03/02 21:56:55 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "limits.h"

char	*get_next_line(int fd);
size_t	ft_str_len(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_str_join(char *s1, char const	*s2);
char	*ft_sub_str(char const *s, unsigned int start, size_t len);
void	ft_str_dup(const char *str, char *ptr);

#endif
