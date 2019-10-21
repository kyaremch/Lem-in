/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:59:30 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/02 10:55:29 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s2;
	unsigned int	i;

	i = 0;
	s2 = (unsigned char *)src;
	while (n)
	{
		if (*s2 == (unsigned char)c)
			return ((void*)s2);
		s2++;
		n--;
	}
	s2 = NULL;
	return ((void*)s2);
}
