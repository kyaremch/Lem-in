/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:58:28 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/05 13:02:04 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char *dest;
	char *help;
	char *sup;
	char *help2;

	if (*s2 == '\0')
		return ((char *)s1);
	dest = (char *)s1;
	sup = (char *)s2;
	while (*dest)
	{
		help = sup;
		help2 = dest;
		while (*help2 && *help && *help == *help2)
		{
			help2++;
			help++;
		}
		if (*help == '\0')
			return (dest);
		if (*dest == '\0')
			return (NULL);
		dest++;
	}
	return (NULL);
}
