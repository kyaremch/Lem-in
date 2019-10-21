/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cust.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:41:57 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/26 14:42:00 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		cust_unsigned(va_list ap)
{
	if (g_type.spec_un == 3)
		return (va_arg(ap, uintmax_t));
	if (g_type.flag_h)
		return ((unsigned short int)va_arg(ap, int));
	if (g_type.flag_l)
		return (va_arg(ap, unsigned long int));
	if (g_type.flag_hh)
		return ((unsigned char)va_arg(ap, int));
	if (g_type.flag_ll)
		return (va_arg(ap, unsigned long long int));
	return (va_arg(ap, unsigned int));
}

intmax_t		cust_signed(va_list ap)
{
	if (g_type.flag_h)
		return ((short int)va_arg(ap, int));
	if (g_type.flag_l)
		return (va_arg(ap, long int));
	if (g_type.flag_hh)
		return ((signed char)va_arg(ap, int));
	if (g_type.flag_ll)
		return (va_arg(ap, long long int));
	return (va_arg(ap, int));
}

long double		cust_float(va_list ap)
{
	if (g_type.flag_long)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}
