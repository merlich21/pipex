/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:51:12 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 19:36:34 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 2147483647)
		write(fd, "2147483647", 10);
	else
	{
		if (n < 0)
		{
			n = -n;
			write(fd, "-", 1);
		}
		if (n / 10 != 0)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}