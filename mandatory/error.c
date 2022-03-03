/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:56:54 by merlich           #+#    #+#             */
/*   Updated: 2022/02/27 19:27:24 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *err_msg, t_data **head)
{
	perror(err_msg);
	ft_delete_list(head);
	exit(EXIT_FAILURE);
}

void	ft_error_input(void)
{
	ft_printf("Error : The program takes 4 arguments.\n");
	ft_printf("Example: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
	exit(EXIT_FAILURE);
}
