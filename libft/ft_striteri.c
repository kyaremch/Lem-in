/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:56:12 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/07 17:27:04 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	char	d;

	if (!s || !f)
		return ;
	i = 0;
	d = (char)i;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}
