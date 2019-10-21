/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specif.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:09 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/25 12:11:10 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_string(va_list ap)
{
	char	*string;
	int		i;

	i = -1;
	string = va_arg(ap, char *);
	if (string == NULL)
		string = "(null)";
	string = string_malloc(string);
	if (g_fl.flag_alen < 0 || (g_fl.flag_alen == 0 && g_fl.flag_a > 0))
		string[0] = '\0';
	if (g_fl.flag_alen > 0)
		string[g_fl.flag_alen] = '\0';
	if (g_fl.flag_m == 0)
		width_move((int)ft_strlen(string));
	while (string[++i] != '\0')
	{
		write_in_buf(string[i]);
	}
	if (g_fl.flag_m > 0)
		width_move((int)ft_strlen(string));
	g_fl.flag_m = 0;
	g_fl.flag_alen = 0;
	free(string);
	ft_bzero(&g_fl, sizeof(g_fl));
	ft_bzero(&g_type, sizeof(g_type));
}

void	if_char(va_list ap)
{
	unsigned char c;

	c = (unsigned char)va_arg(ap, int);
	if (g_fl.flag_m == 0)
		width_move(1);
	write_in_buf(c);
	if (g_fl.flag_m > 0)
		width_move(1);
	ft_bzero(&g_fl, sizeof(g_fl));
	ft_bzero(&g_type, sizeof(g_type));
}

void	if_int(va_list ap)
{
	char		*numb;
	int			j[3];
	intmax_t	i;
	long double	d;

	i = 0;
	numb = NULL;
	d = 0.0;
	j[1] = g_node.i;
	if (g_type.spec_un != 4)
		i = cust_signed(ap);
	else
		d = cust_float(ap);
	if (g_type.spec_un != 4)
		numb = ft_itoa_base(i, 10);
	else
		numb = ffloat(d);
	if (ft_strlen(numb) == 20)
		numb[19] = numb[19] + 1;
	if (i < 0 || d < 0 || 1 / d < 0)
		remuve_min(numb);
	int_help(j, numb);
	ft_bzero(&g_fl, sizeof(g_fl));
	ft_bzero(&g_type, sizeof(g_type));
}

void	if_unsigned(va_list ap)
{
	char		*numb;
	int			j;
	uintmax_t	i;
	int			len;

	i = cust_unsigned(ap);
	if (g_type.spec_un == 2)
		numb = ft_itoa_base_unsigned(i, 8);
	else if (g_type.spec_un == 1 || g_type.spec_un == 0 || g_type.spec_un == 3)
		numb = ft_itoa_base_unsigned(i, 16);
	else
		numb = ft_itoa_base_unsigned(i, 10);
	if (i == 0 && g_fl.flag_h > 0 && g_type.spec_un != 3 && g_type.spec_un != 2)
		g_fl.flag_h -= 1;
	flag_hash_for_spec(numb);
	if (i == 0 && g_fl.flag_h > 0 && g_type.spec_un != 3 && g_type.spec_un == 2)
		g_fl.flag_h -= 1;
	j = (int)ft_strlen(numb);
	len = j;
	spec_unsigned_hash(len, j, numb, i);
	free(numb);
	ft_bzero(&g_fl, sizeof(g_fl));
	ft_bzero(&g_type, sizeof(g_type));
}

void	check_spec(va_list ap, char form)
{
	if (form == 'd' || form == 'i')
		if_int(ap);
	if (form == 'p')
	{
		g_fl.flag_h = 1;
		if_hash('x');
		g_type.spec_un = 3;
		if_unsigned(ap);
	}
	if (form == 'u')
	{
		g_fl.flag_p = 0;
		g_fl.flag_s = 0;
		g_type.spec_un = -1;
		if_unsigned(ap);
	}
	spec_xocs(ap, form);
	if (form == 'f')
	{
		if ((g_fl.flag_alen < 0 && g_fl.flag_a == 0) || g_fl.flag_a == 0)
			g_fl.flag_alen = 6;
		g_type.spec_un = 4;
		if_int(ap);
	}
}
