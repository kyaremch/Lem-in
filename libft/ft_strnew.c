/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:39:04 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/07 10:48:01 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*rez;

	i = 0;
	rez = ft_memalloc(size + 1);
	if (rez == NULL)
		return (rez);
	return (rez);
}
