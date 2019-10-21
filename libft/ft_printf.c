/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:03:16 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/24 16:03:20 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_walid_spec(const char *format)
{
	int i;

	i = g_node.it;
	if (format[i] == '\0')
		return (0);
	while (ft_strchr("-+ #0123456789.hlL", format[i]) != NULL)
	{
		if (format[i] == '-')
			g_fl.flag_m = 1;
		i++;
	}
	if (ft_strchr("diuoxXfFeEgGaAcsSpn", format[i]) != NULL)
		return (1);
	else
	{
		while (ft_strchr("0123456789", format[--i]) != NULL)
			;
		g_fl.width = ft_atoi(&format[i + 1]);
		while (ft_strchr("0123456789", format[++i]) != NULL)
			;
		g_node.it += i - g_node.it;
		return (0);
	}
}

void	ft_min(const char *format, va_list ap)
{
	if (check_walid_spec(format) == 1)
	{
		check_format(format);
		check_spec(ap, format[g_node.it]);
	}
	if (format[g_node.it] != '\0' &&
			ft_strchr("diuoxXfFeEgGaAcsSpn", format[g_node.it]) == NULL)
	{
		if (g_fl.flag_m == 0)
			width_move(g_node.i - (int)ft_strlen(g_node.rez) + 1);
		write_in_buf(format[g_node.it]);
	}
	if (g_fl.flag_m == 1)
		width_move(g_node.i - (int)ft_strlen(g_node.rez) + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	ft_bzero(&g_node, sizeof(g_node));
	ft_bzero(&g_fl, sizeof(g_fl));
	ft_bzero(&g_type, sizeof(g_type));
	while (format[g_node.it] != '\0')
	{
		if (format[g_node.it] == '%')
		{
			g_node.it++;
			if (format[g_node.it] == '\0')
				return (0);
			ft_min(format, ap);
		}
		else
			write_in_buf(format[g_node.it]);
		g_node.it++;
	}
	write(1, g_node.rez, (size_t)g_node.i);
	va_end(ap);
	return (g_node.int_rez);
}
