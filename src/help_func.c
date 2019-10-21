/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:11:26 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:11:27 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_numbof_chars(char *str, char a)
{
	int	i;
	int j;

	i = 0;
	j = -1;
	while (str[++j])
		if (str[j] == a)
			i++;
	return (i);
}

void		capacity(void)
{
	t_ways	*tmp;

	while (g_gen->n_ways->prev)
	{
		if (g_gen->n_ways->len == 1)
			skip_all();
		while (g_gen->n_ways->one_w->next)
			g_gen->n_ways->one_w = g_gen->n_ways->one_w->next;
		g_gen->n_ways = g_gen->n_ways->prev;
	}
	while (g_gen->n_ways->one_w->next)
		g_gen->n_ways->one_w = g_gen->n_ways->one_w->next;
	tmp = g_gen->n_ways;
	while (tmp)
	{
		if (tmp->prev)
			tmp->cap = (tmp->len - tmp->prev->len) * tmp->way_num
			+ tmp->prev->cap;
		tmp = tmp->next;
	}
}

void		print_bonus(void)
{
	t_ways		*tmp;
	t_one_way	*tmp1;

	if (g_gen->ants == 1)
		ft_printf("\nAnts - %d\n", g_gen->ants_d);
	if (g_gen->ways == 1 && g_gen->n_ways)
	{
		tmp = g_gen->n_ways;
		while (tmp)
		{
			tmp1 = tmp->one_w;
			while (tmp1->prev)
				tmp1 = tmp1->prev;
			while (tmp1->next)
			{
				ft_printf("-> %s ", tmp1->room->name);
				tmp1 = tmp1->next;
			}
			ft_printf("Length of way - %d\n", tmp->len);
			tmp = tmp->next;
		}
	}
	exit(0);
}

void		save_pass(t_bfs *buf_saver)
{
	if (!g_gen->buffer)
	{
		if (!(g_gen->buffer = (t_buf *)ft_memalloc(sizeof(t_buf))))
			my_exit(0);
		g_gen->buffer->bfs_buf = buf_saver;
	}
	else
	{
		if (!(g_gen->buffer->next = (t_buf *)ft_memalloc(sizeof(t_buf))))
			my_exit(0);
		g_gen->buffer->next->bfs_buf = buf_saver;
		g_gen->buffer->next->prev = g_gen->buffer;
		g_gen->buffer = g_gen->buffer->next;
	}
}

void		skip_all(void)
{
	print_map();
	g_gen->waves = 1;
	while (g_gen->a_run < g_gen->ants_d)
	{
		g_gen->a_run++;
		ft_printf("L%d-%s ", g_gen->a_run, g_gen->end_rm->name);
	}
	ft_printf("\n");
	if (g_gen->nom == 1)
		ft_printf("\nMove`s - %d\n", g_gen->waves);
	print_bonus();
}
