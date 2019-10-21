/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:07:34 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/02 10:59:32 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s3, const void *s4, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)s3;
	s2 = (unsigned char *)s4;
	while (n--)
		if (*s1 != *s2)
			return ((int)(*s1 - *s2));
		else
		{
			s1++;
			s2++;
		}
	return (0);
}
