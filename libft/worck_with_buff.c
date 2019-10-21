/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worck_with_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:39:08 by kyaremch          #+#    #+#             */
/*   Updated: 2019/02/17 19:39:09 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_in_buf(char c)
{
	g_node.rez[g_node.i++] = c;
	g_node.int_rez++;
	if (g_node.i == 2047)
	{
		write(1, g_node.rez, (size_t)g_node.i);
		g_node.i = 0;
		ft_bzero(g_node.rez, 2048);
	}
}

void	minus_iter(int i)
{
	g_node.i -= i;
	g_node.int_rez -= i;
}
