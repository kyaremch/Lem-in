/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:10:20 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/25 12:10:21 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_hash(char sign)
{
	if (g_fl.flag_h > 0)
	{
		g_fl.sign[0] = '0';
		g_fl.sign[1] = sign;
		g_fl.sign[2] = '\0';
	}
}

void	width_move(int len)
{
	int j;

	j = g_fl.width - len;
	if (g_fl.width == 0)
		return ;
	if (g_fl.flag_z > 0 && (g_fl.flag_a == 0 || g_type.spec_un == 4)
		&& g_fl.flag_alen != -1 && g_fl.flag_m == 0)
		while (j-- > 0)
			write_in_buf('0');
	else
		while (j-- > 0)
			write_in_buf(' ');
	g_fl.width = 0;
	g_fl.flag_m = 0;
}
