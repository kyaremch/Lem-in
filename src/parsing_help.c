/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:11:03 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:11:05 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	help_f(t_rooms *fr_l, t_rooms *sr_l, t_print *fr_out)
{
	if (!fr_l->out_lt)
	{
		if (!(fr_l->out_lt = (t_print *)ft_memalloc(sizeof(t_print))))
			my_exit(0);
		fr_l->out_lt->r_exit = sr_l;
		fr_l->out_lt->curr_room = fr_l;
	}
	else
	{
		fr_out = fr_l->out_lt;
		while (fr_out->next)
			fr_out = fr_out->next;
		if (!(fr_out->next = (t_print *)ft_memalloc(sizeof(t_print))))
			my_exit(0);
		fr_out = fr_out->next;
		fr_out->r_exit = sr_l;
		fr_out->curr_room = fr_l;
	}
}

void	help_s(t_rooms *fr_lt, t_rooms *sr_l, t_print *sr_out)
{
	if (!sr_l->out_lt)
	{
		if (!(sr_l->out_lt = (t_print *)ft_memalloc(sizeof(t_print))))
			my_exit(0);
		sr_l->out_lt->r_exit = fr_lt;
		sr_l->out_lt->curr_room = sr_l;
	}
	else
	{
		sr_out = sr_l->out_lt;
		while (sr_out->next != NULL)
			sr_out = sr_out->next;
		if (!(sr_out->next = (t_print *)ft_memalloc(sizeof(t_print))))
			my_exit(0);
		sr_out = sr_out->next;
		sr_out->r_exit = fr_lt;
		sr_out->curr_room = sr_l;
	}
}
