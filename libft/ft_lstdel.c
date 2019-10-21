/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:00:38 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/09 16:33:06 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *help;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		help = *alst;
		*alst = (*alst)->next;
		del(help->content, help->content_size);
		free(help);
	}
	*alst = NULL;
}
