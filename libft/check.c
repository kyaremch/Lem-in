/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:10:11 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/25 12:10:12 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_end(const char format)
{
	int		i;
	char	*flags;

	i = -1;
	flags = "diuoxXfFeEgGaAcsSpn";
	while (flags[++i] != '\0')
	{
		if (flags[i] == format)
			return (0);
	}
	return (1);
}

void	check_width(const char *format)
{
	int w;
	int j;

	w = ft_atoi(format);
	g_fl.width = w;
	if (w == 0)
		return ;
	j = 0;
	while (w != 0)
	{
		j++;
		w = w / 10;
	}
	g_node.it += j;
}

void	check_accuracy(const char *format)
{
	int acc;
	int j;

	j = 0;
	if (format[g_node.it] == '.')
	{
		g_node.it++;
		g_fl.flag_a++;
		if (format[g_node.it] == '0')
		{
			g_fl.flag_alen = -1;
			g_node.it++;
			return ;
		}
		acc = ft_atoi(&format[g_node.it]);
		g_fl.flag_alen = acc;
		while (acc > 0)
		{
			j++;
			acc = acc / 10;
		}
		g_node.it += j;
	}
	else
		return ;
}

void	check_flag(const char format)
{
	if (format == '-')
	{
		g_fl.flag_m++;
		g_node.it++;
	}
	if (format == '+')
	{
		g_fl.flag_p++;
		g_node.it++;
	}
	if (format == ' ')
	{
		g_fl.flag_s++;
		g_node.it++;
	}
	if (format == '#')
	{
		g_fl.flag_h++;
		g_node.it++;
	}
	if (format == '0')
	{
		g_fl.flag_z++;
		g_node.it++;
	}
}

void	check_format(const char *format)
{
	while (format[g_node.it] != '\0')
	{
		if (check_end(format[g_node.it]) == 1 && format[g_node.it] != '%')
		{
			check_flag(format[g_node.it]);
			check_type(format[g_node.it]);
			if (format[g_node.it] > '0' && format[g_node.it] <= '9')
				check_width(&format[g_node.it]);
			check_accuracy(format);
		}
		else
		{
			if (g_fl.flag_m || g_fl.flag_a)
				g_fl.flag_z = 0;
			break ;
		}
	}
}
