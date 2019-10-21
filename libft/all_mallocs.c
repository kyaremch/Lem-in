/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_mallocs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:09:58 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/25 12:09:59 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string_malloc(const char *string)
{
	char *rez;

	rez = ft_strdup(string);
	return (rez);
}
