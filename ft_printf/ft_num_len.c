/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:51:32 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 19:36:18 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_num_len(long long num, int base)
{
	int	len;

	len = 0;
	if (num < 0)
		len = 2;
	else
		len = 1;
	while (num / base != 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

int	ft_unsigned_num_len(unsigned long long num, int base)
{
	int	len;

	len = 1;
	while (num / base != 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}
