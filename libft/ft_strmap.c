/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:08:16 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/08 12:54:13 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rez;
	int		i;
	int		j;

	rez = NULL;
	if (!s)
		return (rez);
	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	rez = (char *)malloc(sizeof(char) * i + 1);
	if (rez == NULL)
		return (rez);
	while (j < i)
	{
		rez[j] = f(s[j]);
		j++;
	}
	rez[j] = '\0';
	return (rez);
}
