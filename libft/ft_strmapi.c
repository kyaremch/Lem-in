/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:45:55 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/08 12:55:52 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*rez;
	char			d;

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
		d = (unsigned int)j;
		rez[j] = f(j, s[j]);
		j++;
	}
	rez[j] = '\0';
	return (rez);
}
