/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:05:49 by kyaremch          #+#    #+#             */
/*   Updated: 2018/10/26 17:50:39 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)dest;
	while (i < n)
	{
		s1[i] = c;
		i++;
	}
	return (dest);
}
