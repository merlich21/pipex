/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/22 22:13:50 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>

/*  */
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const	*s1, char const	*s2);

/* numbers.c */
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_uint(unsigned long long num, int fd);
int	ft_int_dec(int num, int fd);
int	ft_putnbr_h_fd(unsigned long long num, int flag, int fd);

/* charactes.c */
int	ft_char(char c, int fd);
int	ft_string(char *str, int fd);

/* ft_num_len.c */
int	ft_num_len(long long num, int base);
int	ft_unsigned_num_len(unsigned long long num, int base);

/*  */
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/* ft_printf.c */
int	ft_printf(const char *format, ...);

#endif
