/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:56:54 by merlich           #+#    #+#             */
/*   Updated: 2022/02/24 22:00:20 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	 ft_error(char *err_msg, t_data **head)
{
	perror(err_msg);
	ft_delete_list(head);
	exit(EXIT_FAILURE);
}
