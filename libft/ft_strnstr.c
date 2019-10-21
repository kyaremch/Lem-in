/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:09:47 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/08 15:50:40 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*rez;
	size_t	j;

	rez = (char *)s1;
	j = ft_strlen(s2);
	if (j == 0)
		return (rez);
	while (*rez && n-- >= j)
	{
		if (ft_memcmp(rez, s2, j) == 0)
			return (rez);
		rez++;
	}
	return (NULL);
}
