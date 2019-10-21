/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:11:19 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/08 13:20:49 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*rez;
	unsigned int	j;

	rez = NULL;
	if (!s)
		return (rez);
	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	rez = (char *)malloc(sizeof(char) * len + 1);
	if (rez == NULL)
		return (NULL);
	while (j < len)
	{
		rez[j] = s[start];
		start++;
		j++;
	}
	rez[j] = '\0';
	return (rez);
}
