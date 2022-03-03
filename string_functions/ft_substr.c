/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:26:46 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 19:37:52 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	size_t	s_len;
	char	*sub_str;

	i = 0;
	size = len;
	if (NULL == s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		size = s_len;
	sub_str = malloc(size + 1);
	if (NULL == sub_str)
		return (NULL);
	else if (!((*s == '\0') || (start >= s_len)))
	{
		while (i < size)
		{
			sub_str[i] = s[start + i];
			i++;
		}
	}
	sub_str[i] = '\0';
	return (sub_str);
}
