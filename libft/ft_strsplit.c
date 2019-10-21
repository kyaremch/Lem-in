/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:19:39 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/09 13:24:38 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t		len_of_str(char const *str, char c)
{
	size_t len_of_str;

	len_of_str = 0;
	while (str[len_of_str] && str[len_of_str] != c)
		len_of_str++;
	return (len_of_str + 1);
}

static size_t		row_of_str(char const *str, char c)
{
	size_t row_of_str;
	size_t i;

	i = 0;
	row_of_str = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			row_of_str++;
		i++;
	}
	return (row_of_str);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**dest;
	size_t		k;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!str)
		return (NULL);
	k = row_of_str(str, c);
	if (!(dest = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	i = -1;
	while (++i < k)
	{
		j = 0;
		while (*str == c)
			str++;
		len = len_of_str(str, c);
		if (!(dest[i] = ft_strnew(len)))
			return (NULL);
		while (j < len - 1)
			dest[i][j++] = *str++;
	}
	dest[i] = 0;
	return (dest);
}
