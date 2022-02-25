/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:44 by merlich           #+#    #+#             */
/*   Updated: 2022/02/25 19:34:26 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <errno.h>

typedef struct s_data
{
	char			*path;
	char			**flags;

	pid_t			pid;

	int				infile;
	int				outfile;

	int				fildes[2];

	struct s_data	*next;
}	t_data;

/* STRING_FUNCTIONS FOLDER */
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const	*s1, char const	*s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
void	ft_delete_tab(char **tab);

/* FT_PRINTF FOLDER */
/* numbers.c */
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		ft_uint(unsigned long long num, int fd);
int		ft_int_dec(int num, int fd);
int		ft_putnbr_h_fd(unsigned long long num, int flag, int fd);

/* charactes.c */
int		ft_char(char c, int fd);
int		ft_string(char *str, int fd);

/* ft_num_len.c */
int		ft_num_len(long long num, int base);
int		ft_unsigned_num_len(unsigned long long num, int base);

/*  */
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/* ft_printf.c */
int		ft_printf(const char *format, ...);

/* LIST_FUNCTIONS FOLDER*/
/* list_functions.c */
void	ft_push(t_data **head, char *path);
void	ft_delete_list(t_data **head);
int		ft_list_size(t_data *head);
t_data	*ft_list_last(t_data *head);
t_data	*ft_stack_last_but_one(t_data *lst);

/* MANDATORY FOLDER */
/* stdin_parser.c */
void	ft_fill_list(t_data *head, char **envp);
void	ft_check_files(char **argv);

/* error.c */
void	ft_error(char *err_msg, t_data **head);
void	ft_error_input(void);

/* childs.c */
void	first_child(t_data *head, char **envp);
void	second_child(t_data *head, char **envp);

/* close_fd.c */
void	ft_close_fd(t_data *head);

#endif
