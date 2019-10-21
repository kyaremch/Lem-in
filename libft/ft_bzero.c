/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:51:43 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/07 15:11:41 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;
	unsigned int	i;

	s1 = (unsigned char *)s;
	i = 0;
	while (n)
	{
		s1[i] = '\0';
		i++;
		n--;
	}
}
