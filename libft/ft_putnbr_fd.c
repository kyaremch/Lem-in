/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:22:01 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/08 14:21:10 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	one_numb(int nb, int fd)
{
	char c;

	if (nb >= 10 || nb <= -10)
	{
		one_numb(nb / 10, fd);
		one_numb(nb % 10, fd);
	}
	else
	{
		if (nb >= 0)
		{
			c = nb + '0';
			write(fd, &c, 1);
		}
		else
		{
			c = -1 * nb + '0';
			write(fd, &c, 1);
		}
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (fd < 0)
		return ;
	if (nb < 0)
		write(fd, "-", 1);
	one_numb(nb, fd);
}
