/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:28:50 by merlich           #+#    #+#             */
/*   Updated: 2022/02/24 22:29:55 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(t_data *head)
{
	close(head->infile);
	close(head->outfile);
	close(head->fildes[0]);
	close(head->fildes[1]);
}
