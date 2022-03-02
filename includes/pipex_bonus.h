/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:17:44 by merlich           #+#    #+#             */
/*   Updated: 2022/03/02 22:12:54 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
# include "../get_next_line/get_next_line_bonus.h"

typedef struct s_data
{
	char			*cmd;
	char			**cmd_paths;
	char			**argv;

	pid_t			pid;
	int				cmd_index;

	int				infile;
	int				outfile;

	int				cmd_num;
	int				pipe_num;
	int				*pipe;

	int				here_doc;
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

/* BONUS FOLDER */
/* pipex_bonus.c */
void	ft_get_cmd_paths(t_data *head, char **envp);

/* error_bonus.c */
void	ft_error_parent(char *err_msg, t_data *head);
void	ft_error_child(char *err_msg, t_data *head);
void	ft_error_input(void);

/* childs_bonus.c */
void	ft_child(t_data head, char **argv, char **envp);

/* close_fd_bonus.c */
void	ft_close_pipes(t_data *head);
void	ft_close_fd(t_data *head);
void	ft_free_tab(char **tab);
void	ft_free_struct(t_data *head);
void	ft_free_parent(t_data *head);
void	ft_free_child(t_data *head);

/* infile_outfile_bonus.c */
void	ft_init_fildes(t_data *head, int argc, char **argv);

/* here_doc_bonus.c */
void	ft_fill_here_doc(t_data *head, char **argv);

#endif
