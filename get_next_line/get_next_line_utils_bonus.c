/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:17:38 by merlich           #+#    #+#             */
/*   Updated: 2022/03/02 20:26:42 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = "";
	while (i < ft_str_len(s))
	{
		if ((unsigned char) s[i] == (unsigned char) c)
		{
			res = (char *)s + i + 1;
			return (res);
		}
		i++;
	}
	return (res);
}

char	*ft_str_join(char *s1, char const	*s2)
{
	size_t	i;
	char	*new_str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc((sizeof(char)) * (ft_str_len(s1) + ft_str_len(s2) + 1));
	if (NULL == new_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_sub_str(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	size_t	s_len;
	char	*substr;

	i = 0;
	size = len;
	if (NULL == s)
		return (NULL);
	s_len = ft_str_len(s);
	if (len > s_len)
		size = s_len;
	substr = malloc(sizeof(char) * (size + 1));
	if (NULL == substr)
		return (NULL);
	else if (!((*s == '\0') || (start >= s_len)))
	{
		while (i < size)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = '\0';
	return (substr);
}

void	ft_str_dup(const char *str, char *ptr)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
}
