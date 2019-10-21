/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:07:35 by kyaremch          #+#    #+#             */
/*   Updated: 2018/11/11 12:06:29 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *help;
	t_list *rez;

	if (!lst || !f)
		return (NULL);
	rez = f(lst);
	help = rez;
	lst = lst->next;
	while (lst)
	{
		if (f(lst))
		{
			rez->next = f(lst);
			rez = rez->next;
		}
		rez->next = NULL;
		lst = lst->next;
	}
	return (help);
}
