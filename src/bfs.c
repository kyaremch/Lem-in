/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:09:42 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:09:47 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		write_way(void)
{
	t_ways		*tmp;

	tmp = g_gen->n_ways;
	if (!g_gen->n_ways)
	{
		if (!(g_gen->n_ways = (t_ways *)ft_memalloc(sizeof(t_ways))))
			my_exit(0);
		g_gen->n_ways->prev = NULL;
		tmp = g_gen->n_ways;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_ways *)ft_memalloc(sizeof(t_ways))))
			my_exit(0);
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	put_rooms_into_way(0);
	tmp->way_num = g_gen->n_ways_d++;
	if (g_gen->n_ways_d < 12 && g_gen->n_ways_d < g_gen->ants_d)
		algo();
}

static int		check_prev(t_rooms *r_exit, t_bfs *bfs_head)
{
	t_bfs		*tmp;

	tmp = bfs_head;
	while (tmp)
	{
		if (tmp->curr_room == r_exit || r_exit->status == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void		add_room(t_bfs *buf_saver, const t_print *ptr)
{
	t_bfs		*tmp;

	tmp = buf_saver;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = (t_bfs *)ft_memalloc(sizeof(t_bfs))))
		my_exit(0);
	tmp->next->curr_room = ptr->r_exit;
	tmp->next->prev = tmp;
	tmp->next->parent = ptr->curr_room;
	ptr->r_exit->parent = ptr->curr_room;
	tmp->next->next = NULL;
}

void			algo(void)
{
	t_bfs		*buf_saver;
	t_bfs		*bfs_head;
	t_print		*ptr;

	if (!(buf_saver = (t_bfs *)ft_memalloc(sizeof(t_bfs))))
		my_exit(0);
	buf_saver->curr_room = g_gen->start_rm;
	save_pass(buf_saver);
	bfs_head = buf_saver;
	while (buf_saver)
	{
		ptr = buf_saver->curr_room->out_lt;
		while (ptr)
		{
			if (check_prev(ptr->r_exit, bfs_head))
			{
				add_room(buf_saver, ptr);
				if (ptr->r_exit == g_gen->end_rm)
					write_way();
			}
			ptr = ptr->next;
		}
		buf_saver = buf_saver->next;
	}
	buf_saver = bfs_head;
}
