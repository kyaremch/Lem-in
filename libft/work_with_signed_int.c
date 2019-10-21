/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_signed_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:41:25 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/26 14:41:27 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		remuve_min(char *numb)
{
	int j;

	j = 0;
	g_fl.flag_p = -1;
	g_fl.paste_or++;
	if (g_fl.flag_p < 0)
	{
		while (numb[j + 1] != '\0')
		{
			numb[j] = numb[j + 1];
			j++;
		}
		numb[j] = '\0';
	}
}

void		if_flag_h(int j)
{
	if (g_fl.flag_h > 0 && g_fl.flag_z == 0 && g_type.spec_un == 2
		&& (g_fl.width < j || g_fl.flag_m != 0) && g_fl.flag_h--)
		write_in_buf(g_fl.sign[0]);
	if (g_type.spec_un == 2 && g_fl.flag_h > 0 && g_fl.flag_z > 0
		&& g_fl.width < j)
		write_in_buf(g_fl.sign[0]);
	if (g_fl.flag_h && g_type.spec_un != 2 && g_fl.flag_z)
	{
		write_in_buf(g_fl.sign[0]);
		write_in_buf(g_fl.sign[1]);
		g_fl.flag_h = 0;
	}
	if (g_fl.paste_or && g_fl.flag_a == 0 &&
		g_fl.flag_p > 0 && g_fl.width == 0 && g_fl.paste_or--)
		write_in_buf('+');
	if (g_fl.paste_or && g_fl.flag_p > 0 && g_fl.width == 0 && g_fl.paste_or--)
		write_in_buf('+');
}

int			int_parth_positive(int len, int j)
{
	if (g_fl.flag_p && (g_fl.flag_s == 0 || g_fl.flag_s--))
		g_fl.paste_or++;
	if (g_fl.flag_a != 0 && g_fl.flag_alen > j)
		j = g_fl.flag_alen;
	if (g_fl.flag_p > 0 || (g_fl.flag_h > 0 && g_type.spec_un == 2))
		j++;
	if_flag_h(j);
	if (g_fl.paste_or && g_fl.width != 0 && g_fl.flag_z > 0
		&& g_fl.flag_a == 0 && g_fl.flag_p > 0 && g_fl.paste_or--)
		write_in_buf('+');
	if (g_fl.flag_s != 0 && g_fl.flag_p == 0)
	{
		j++;
		write_in_buf(' ');
	}
	if ((g_fl.width > 0 || g_fl.flag_z > 0) && g_fl.flag_m == 0)
		width_move(j);
	if (g_fl.paste_or && g_fl.flag_p > 0 && g_fl.paste_or--)
		write_in_buf('+');
	if (g_fl.flag_alen > len)
		g_fl.flag_s = 0;
	if (g_fl.flag_alen > 0)
		while (g_fl.flag_alen-- > len)
			write_in_buf('0');
	return (j);
}

void		int_parth_negative(int len, int j)
{
	if (g_fl.flag_a != 0 && g_fl.flag_alen > j)
		j = g_fl.flag_alen;
	if (g_fl.flag_p < 0 || g_type.spec_un == 4)
		j++;
	if (g_fl.flag_a == 0 && g_fl.width == 0 && g_fl.paste_or--)
		write_in_buf('-');
	if (g_fl.paste_or && g_fl.width == 0 && g_fl.paste_or--)
		write_in_buf('-');
	if (g_fl.paste_or && g_fl.width != 0 && g_fl.flag_z > 0
		&& (g_fl.flag_a == 0 || g_type.spec_un == 4) && g_fl.paste_or--)
		write_in_buf('-');
	if ((g_fl.width > 0 || g_fl.flag_z > 0) && g_fl.flag_m == 0)
		width_move(j);
	if (g_fl.paste_or && g_fl.paste_or--)
		write_in_buf('-');
	if (g_fl.flag_alen > 0)
		while (g_fl.flag_alen-- > len)
			write_in_buf('0');
	if (g_fl.flag_s != 0 && g_fl.flag_p == 0 && g_fl.flag_z == 0)
		write_in_buf(' ');
}
