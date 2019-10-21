/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:20:38 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/08 13:23:34 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static char	*ft_concat(char const *s1, char const *s2, char *rez)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		rez[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		rez[i] = s2[j];
		j++;
		i++;
	}
	rez[i] = '\0';
	return (rez);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*rez;
	int		i;
	int		j;

	rez = NULL;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s2 && !s1)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	rez = (char *)malloc(sizeof(char) * (i + j + 1));
	if (rez == NULL)
		return (NULL);
	rez = ft_concat(s1, s2, rez);
	return (rez);
}
