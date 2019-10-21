/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:02:17 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/07 10:43:42 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*rez;

	if (!(rez = malloc(size)))
		return (NULL);
	ft_memset(rez, 0, size);
	return (rez);
}
