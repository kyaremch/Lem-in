/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:41:10 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/26 14:41:12 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_hash_for_spec(char *numb)
{
	if (g_fl.flag_a && (g_fl.flag_alen == 0 || g_fl.flag_alen == -1)
		&& numb[0] == '0' && !g_fl.flag_h)
		numb[0] = '\0';
	if (g_fl.flag_h && g_fl.flag_z && (size_t)g_fl.width < ft_strlen(numb))
		g_fl.flag_z = 0;
	if (g_fl.flag_h && g_fl.flag_z && (size_t)g_fl.width > ft_strlen(numb)
		&& g_fl.flag_a && g_fl.flag_alen == 0 && g_type.spec_un == 2)
		g_fl.flag_h = 0;
}

void		spec_unsigned_hash(int len, int j, char *numb, uintmax_t i)
{
	if (g_fl.flag_h > 0 && g_type.spec_un != 2 &&
		(i != 0 || (g_type.spec_un == 3 && i == 0)))
		j += 2;
	j = int_parth_positive(len, j);
	if (g_fl.flag_h > 0 && g_type.spec_un != 2)
	{
		write_in_buf(g_fl.sign[0]);
		write_in_buf(g_fl.sign[1]);
	}
	if (ft_strchr(&g_node.rez[g_node.i], g_fl.sign[0]) == NULL
		&& g_type.spec_un == 2 && g_fl.flag_h > 0)
		write_in_buf(g_fl.sign[0]);
	len = -1;
	while (numb[++len] != '\0')
		write_in_buf(numb[len]);
	if (g_fl.flag_m != 0)
		width_move(j);
}

void		spec_xocs(va_list ap, char form)
{
	if (form == 'x' || form == 'o')
	{
		g_fl.flag_p = 0;
		if (form == 'o')
		{
			g_type.spec_un = 2;
			if_hash('0');
		}
		if (g_type.spec_un != 2)
			if_hash('x');
		if_unsigned(ap);
	}
	if (form == 'X')
	{
		g_type.spec_un = 1;
		if_hash('X');
		if_unsigned(ap);
	}
	if (form == 'c')
		if_char(ap);
	if (form == 's')
		if_string(ap);
}

void		int_help(int *j, char *numb)
{
	int i;

	if (g_fl.flag_a > 0 && (g_fl.flag_alen == 0 || g_fl.flag_alen == -1)
		&& numb[0] == '0' && g_type.spec_un != 4)
		numb[0] = '\0';
	j[0] = (int)ft_strlen(numb);
	j[2] = j[0];
	if (g_fl.flag_p >= 0)
		int_parth_positive(j[2], j[0]);
	else
		int_parth_negative(j[2], j[0]);
	i = -1;
	while (numb[++i] != '\0')
	{
		write_in_buf(numb[i]);
	}
	j[1] = g_node.i - j[1];
	if (g_fl.flag_m != 0)
		width_move(j[1]);
	if (ft_strcmp(numb, "inf") != 0 && ft_strcmp(numb, "nan") != 0)
		free(numb);
}
