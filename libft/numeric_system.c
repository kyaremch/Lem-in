/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_system.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:10:56 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/25 12:10:58 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_length(intmax_t nb, int base)
{
	intmax_t	tmp;
	int			j;

	if (nb == 0)
		return (1);
	j = 0;
	tmp = nb;
	while (tmp != 0)
	{
		j++;
		tmp = tmp / base;
	}
	return (j);
}

int			ft_length_unsigned(uintmax_t nb, int base)
{
	uintmax_t	tmp;
	int			j;

	if (nb == 0)
		return (1);
	j = 0;
	tmp = nb;
	while (tmp != 0)
	{
		j++;
		tmp = tmp / base;
	}
	return (j);
}

char		*rez_write(intmax_t nb, int base, char *rez, int flag)
{
	int i;

	i = ft_length(nb, base);
	if (!(rez = malloc(sizeof(char) * (i + flag + 1))))
		exit(0);
	rez[i + flag] = '\0';
	while (i-- > 0)
	{
		if (g_type.spec_un == 1)
			rez[i + flag] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		else
			rez[i + flag] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb = nb / base;
	}
	return (rez);
}

char		*ft_itoa_base(intmax_t nb, int base)
{
	intmax_t	i;
	char		*rez;
	int			flag;

	i = 1;
	flag = 0;
	rez = NULL;
	if (nb == LONG_LONG_MIN)
	{
		flag = 1;
		nb = LONG_LONG_MAX;
	}
	if (nb < 0)
	{
		if (base == 10)
			flag = 1;
		nb *= -1;
	}
	if (g_fl.flag_p == -1 && g_type.spec_un == 4)
		flag = 1;
	rez = rez_write(nb, base, rez, flag);
	if (flag == 1)
		rez[0] = '-';
	return (rez);
}

char		*ft_itoa_base_unsigned(uintmax_t nb, int base)
{
	uintmax_t	i;
	char		*rez;

	i = 1;
	i = (uintmax_t)ft_length_unsigned(nb, base);
	if (!(rez = malloc(sizeof(char) * i)))
		exit(0);
	rez[i] = '\0';
	while (i-- > 0)
	{
		if (g_type.spec_un == 1)
			rez[i] = (nb % base) + (nb % base > 9 ? 'A' - 10 : '0');
		else
			rez[i] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb = nb / base;
	}
	return (rez);
}
