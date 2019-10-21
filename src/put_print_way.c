/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_print_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:11:57 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:11:58 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		put_rooms_into_way(int i)
{
	t_one_way		*way;
	t_rooms			*curr_room;

	if (!(way = (t_one_way *)ft_memalloc(sizeof(t_one_way))))
		my_exit(0);
	curr_room = g_gen->end_rm;
	way->room = curr_room;
	while (curr_room)
	{
		i++;
		if (!(way->prev = (t_one_way *)ft_memalloc(sizeof(t_one_way))))
			my_exit(0);
		way->prev->next = way;
		way = way->prev;
		way->room = curr_room;
		if (curr_room != g_gen->start_rm && curr_room != g_gen->end_rm)
			curr_room->status = 1;
		curr_room = curr_room->parent;
	}
	while (g_gen->n_ways->next)
		g_gen->n_ways = g_gen->n_ways->next;
	g_gen->n_ways->len = i;
	g_gen->n_ways->one_w = way;
}

void		from_rom_to_room(t_one_way **path, int l, t_ways *ways)
{
	if ((*path)->room == g_gen->end_rm && (*path)->prev->n_lem != 0
	&& g_gen->a_out > 0)
	{
		if (g_gen->no_moves != 1)
			ft_printf("L%d-%s ", (*path)->prev->n_lem, (*path)->room->name);
		(*path)->prev->n_lem = 0;
		g_gen->a_out--;
	}
	else if (l == 0 && (*path)->prev->n_lem != 0 && (*path)->room !=
	g_gen->end_rm)
	{
		if (g_gen->no_moves != 1)
			ft_printf("L%d-%s ", (*path)->prev->n_lem, (*path)->room->name);
		(*path)->n_lem = (*path)->prev->n_lem;
		(*path)->prev->n_lem = 0;
	}
	else if (l == 1 && ways->cap < (g_gen->ants_d - g_gen->a_run)
		&& g_gen->a_run < g_gen->ants_d)
	{
		g_gen->a_run++;
		(*path)->n_lem = g_gen->a_run;
		if (g_gen->no_moves != 1)
			ft_printf("L%d-%s ", (*path)->n_lem, (*path)->room->name);
	}
}

void		print_map(void)
{
	t_data	*tmp;

	tmp = g_gen->data;
	while (tmp)
	{
		ft_printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void		ants_go(void)
{
	t_ways		*n_way;
	t_one_way	*path;

	capacity();
	while (g_gen->a_out > 0)
	{
		n_way = g_gen->n_ways;
		while (n_way && g_gen->a_out > 0)
		{
			path = n_way->one_w;
			while (path && path->room != g_gen->start_rm)
			{
				if (path->n_lem == 0 && path->prev->room == g_gen->start_rm
					&& g_gen->a_run <= g_gen->ants_d)
					from_rom_to_room(&path, 1, n_way);
				else if (path->n_lem == 0 && path->prev->n_lem != 0)
					from_rom_to_room(&path, 0, n_way);
				path = path->prev;
			}
			n_way = n_way->next;
		}
		if (g_gen->no_moves != 1)
			write(1, "\n", 1);
		g_gen->waves++;
	}
}
