/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:05:01 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/07 14:07:38 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned char	i;
	unsigned char	j;
	size_t			rez;

	i = 0;
	j = 0;
	rez = 0;
	while (src[rez])
		rez++;
	while (dest[i] && i < size)
		i++;
	rez = rez + i;
	while (src[j] != '\0' && size != 0 && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dest[i] = '\0';
	return (rez);
}
