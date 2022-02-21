/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:36:52 by merlich           #+#    #+#             */
/*   Updated: 2022/02/21 21:38:47 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_char(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_string(char *str, int fd)
{
	if (NULL == str)
	{
		str = "(null)";
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
