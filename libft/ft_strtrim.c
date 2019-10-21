/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:58:17 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/08 14:33:39 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static char			*writer(char *rez, const char *s, size_t i, size_t j)
{
	unsigned int k;

	k = 0;
	while (k <= i)
	{
		rez[k] = s[j];
		k++;
		j++;
	}
	rez[k] = '\0';
	return (rez);
}

static unsigned int	size_finder(char const *s)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	if (j == i + 1)
		return (1);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	i = i - j;
	return (i);
}

char				*ft_strtrim(char const *s)
{
	char			*rez;
	unsigned int	i;
	unsigned int	j;

	rez = NULL;
	if (!s)
		return (rez);
	j = 0;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	i = size_finder(s);
	rez = (char *)malloc(sizeof(char) * i + 2);
	if (rez == NULL)
		return (NULL);
	rez[0] = '\0';
	if (i == 1)
		return (rez);
	return (writer(rez, s, i, j));
}
