/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:56:54 by merlich           #+#    #+#             */
/*   Updated: 2022/03/04 23:44:21 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_error_child(char *err_msg, t_data *head)
{
	perror(err_msg);
	ft_free_child(head);
	exit(EXIT_FAILURE);
}

void	ft_error_parent(char *err_msg, t_data *head)
{
	perror(err_msg);
	ft_free_parent(head);
	exit(EXIT_FAILURE);
}

void	ft_error_input(void)
{
	ft_printf("Error : The program takes 4 arguments.\n");
	ft_printf("Example: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
	exit(EXIT_FAILURE);
}
