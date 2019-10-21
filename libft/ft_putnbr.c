/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:03:25 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/02 08:58:32 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	numb(int nb)
{
	if (nb >= 10 || nb <= -10)
	{
		numb(nb / 10);
		numb(nb % 10);
	}
	else
	{
		if (nb >= 0)
			ft_putchar(nb + '0');
		else
			ft_putchar(-1 * nb + '0');
	}
}

void		ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	numb(nb);
}
