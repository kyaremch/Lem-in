/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:10:40 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:10:42 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		parce_end(t_data **lt)
{
	if (!lt || !(*lt) || !(*lt)->data || !(*lt)->data[0]
	|| !(*lt)->data[1])
		my_exit(6);
	g_gen->n_end = 1;
	while ((*lt)->data[0] == '#' && (*lt)->data[1] != '#')
		*lt = (*lt)->next;
	if ((*lt)->data[0] == '#' && (*lt)->data[1] == '#')
	{
		ft_printf("%s\n", (*lt)->data);
		my_exit(6);
	}
	if (ft_numbof_chars((*lt)->data, ' ') == 2)
		parce_rooms((*lt)->data, 2);
	else
	{
		ft_printf("%s\n", (*lt)->data);
		my_exit(6);
	}
}

t_data			*parce_all(t_data *lt, int c)
{
	if (g_gen->ants_d < 1)
		my_exit(2);
	if (c == 1 && g_gen->n_st == 0)
	{
		g_gen->n_st = 1;
		while (lt->data[0] == '#' && lt->data[1] != '#')
			lt = lt->next;
		if (lt->data[0] == '#' && lt->data[1] == '#')
			my_exit(6);
		if (ft_numbof_chars(lt->data, ' ') == 2)
			parce_rooms(lt->data, 1);
		else
		{
			ft_printf("%s\n", lt->data);
			my_exit(6);
		}
	}
	else if (c == 2 && g_gen->n_end == 0)
		parce_end(&lt);
	else if ((c == 1 && g_gen->n_st == 1)
		|| (c == 2 && g_gen->n_end == 1))
		my_exit(3);
	return (lt);
}

void			parce_f(t_rooms *fr_l, t_rooms *sr_l, t_print *fr_out)
{
	if (!fr_l || !g_gen->start_rm
		|| !g_gen->end_rm || !sr_l)
		my_exit(6);
	if ((ft_strcmp(fr_l->name, g_gen->start_rm->name) == 0 &&
		ft_strcmp(sr_l->name, g_gen->end_rm->name) == 0) ||
		(ft_strcmp(sr_l->name, g_gen->start_rm->name) == 0 &&
		ft_strcmp(fr_l->name, g_gen->end_rm->name) == 0))
		skip_all();
	help_f(fr_l, sr_l, fr_out);
}

void			parce_s(t_rooms *fr_lt, t_rooms *sr_l, t_print *sr_out)
{
	if (!fr_lt || !g_gen->start_rm
		|| !g_gen->end_rm || !sr_l)
		my_exit(6);
	help_s(fr_lt, sr_l, sr_out);
}

void			parce_way(char *str)
{
	char	**mas;
	t_rooms	*fr_lt;
	t_rooms	*sr_lt;
	t_print	*fr_out;
	t_print	*sr_out;

	fr_out = NULL;
	sr_out = NULL;
	mas = ft_strsplit(str, '-');
	if (!mas[0] || !mas[1] || ft_strcmp(mas[0], mas[1]) == 0)
	{
		ft_printf("%s\n", str);
		my_exit(6);
	}
	fr_lt = g_gen->n_rooms;
	sr_lt = g_gen->n_rooms;
	while (fr_lt && ft_strcmp(fr_lt->name, mas[0]) != 0)
		fr_lt = fr_lt->prev;
	while (sr_lt && ft_strcmp(sr_lt->name, mas[1]) != 0)
		sr_lt = sr_lt->prev;
	parce_f(fr_lt, sr_lt, fr_out);
	parce_s(fr_lt, sr_lt, sr_out);
	free(mas[0]);
	free(mas[1]);
	free(mas);
}
