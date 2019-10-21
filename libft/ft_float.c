/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:10:31 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/25 12:10:32 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	befor(long double nb)
{
	intmax_t rez;

	rez = (intmax_t)nb;
	return (rez);
}

char		*after(long double nb, intmax_t bef)
{
	char	*rez;
	int		h;
	int		i;

	nb = nb - bef;
	if (nb < 0)
		nb *= -1;
	i = 0;
	if (!(rez = malloc(sizeof(char) * g_fl.flag_alen + 1)))
		exit(0);
	if (g_fl.flag_alen == -1)
		g_fl.flag_alen = 0;
	while (i < g_fl.flag_alen + 1)
	{
		h = nb * 10;
		rez[i] = h + '0';
		i++;
		nb = nb * 10 - h;
	}
	rez[i] = '\0';
	return (rez);
}

char		*rounding(char *rez2)
{
	int i;

	i = 0;
	while (rez2[i])
		i++;
	while (rez2[--i] == '9' || (i + 1 > g_fl.flag_alen && rez2[i] > '5'))
		rez2[i] = '0';
	if (i < 0)
		g_fl.flag_fl = 1;
	if (rez2[i] > '5')
		rez2[i] = '0';
	else
		rez2[i] += 1;
	rez2[g_fl.flag_alen] = '\0';
	return (rez2);
}

char		*if_ponint(char *rez1, char *rez2)
{
	if (g_fl.flag_alen > 0 || g_fl.flag_h > 0)
		rez1 = ft_strjoin(rez1, ".");
	if (rez1 && rez2)
		rez1 = ft_strjoin(rez1, rez2);
	g_fl.flag_alen = 0;
	return (rez1);
}

char		*ffloat(long double nb)
{
	char		*rez1;
	char		*rez2;
	intmax_t	bef;

	if (nb == 0.0)
		if (1 / nb < 0)
			g_fl.flag_p = -1;
	if ((nb * 2 == nb && nb != 0 && nb < 0)
		|| (nb * 2 == nb && nb != 0 && nb > 0) || nb != nb)
	{
		g_fl.flag_alen = 3;
		if (nb != nb)
			return ("nan");
		return ("inf");
	}
	bef = befor(nb);
	rez2 = after(nb, bef);
	if (g_fl.flag_alen == 0 && ((bef % 2 != 0 && rez2[0] >= '5')
		|| (bef % 2 == 0 && nb - bef > 0.5)))
		g_fl.flag_fl = 1;
	rez2 = rounding(rez2);
	bef += g_fl.flag_fl;
	rez1 = ft_itoa_base(bef, 10);
	rez1 = if_ponint(rez1, rez2);
	return (rez1);
}
