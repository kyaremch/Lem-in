/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:02:58 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/07 14:17:53 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*the_writer(char *rez, int n, int j)
{
	if (n == 0)
	{
		rez[0] = n + '0';
		return (rez);
	}
	rez[j] = '\0';
	while (n >= 1)
	{
		j--;
		rez[j] = n % 10 + '0';
		n = n / 10;
	}
	return (rez);
}

static int		size_finder(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = n * (-1);
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char	*rez;
	int		j;

	j = size_finder(n);
	if (n >= 0)
	{
		rez = malloc(j + 1);
		if (rez == NULL)
			return (NULL);
	}
	else
	{
		rez = malloc(j + 2);
		if (rez == NULL)
			return (NULL);
		j = j + 1;
		rez[0] = '-';
		if (n == -2147483648)
		{
			rez[1] = '2';
			n = -147483648;
		}
		n = n * (-1);
	}
	return (the_writer(rez, n, j));
}
