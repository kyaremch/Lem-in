/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:41:44 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/26 14:41:45 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_fl_h(const char format)
{
	if (format == 'h' && g_type.flag_h == 0)
	{
		g_type.flag_h++;
		g_node.it++;
		return ;
	}
	if (format == 'h' && g_type.flag_h == 1)
	{
		g_type.flag_h = 0;
		g_type.flag_hh++;
		g_node.it++;
	}
}

void	check_type(const char format)
{
	check_fl_h(format);
	if (format == 'l' && g_type.flag_l == 0)
	{
		g_type.flag_l++;
		g_node.it++;
		return ;
	}
	if (format == 'l' && g_type.flag_l == 1)
	{
		g_type.flag_l = 0;
		g_type.flag_ll++;
		g_node.it++;
	}
	if (format == 'L')
	{
		g_type.flag_long++;
		g_node.it++;
	}
}
