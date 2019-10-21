/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:22:23 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/02 11:08:05 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = -1;
	if (src)
	{
		while (src[++i] != '\0')
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (dst);
}
