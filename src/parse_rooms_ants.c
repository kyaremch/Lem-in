/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:10:52 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:10:53 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		parce_ant(char *str, int i)
{
	if (str && *str)
	{
		i = 0;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0')
		{
			g_gen->ants_d = ft_atoi(str);
			g_gen->a_out = g_gen->ants_d;
		}
		else
			my_exit(1);
		if (g_gen->ants_d <= 0)
			my_exit(1);
	}
}

static void	parce_room2(char **room, int a)
{
	g_gen->n_rooms->name = room[0];
	g_gen->n_rooms->x = room[1];
	g_gen->n_rooms->y = room[2];
	if (a == 1)
	{
		g_gen->n_rooms->flag = 1;
		g_gen->start_rm = g_gen->n_rooms;
	}
	else if (a == 2)
	{
		g_gen->n_rooms->flag = 2;
		g_gen->end_rm = g_gen->n_rooms;
	}
	free(room);
}

void		parce_rooms(char *str, int a)
{
	char	**room;
	t_rooms	*end_room_lt;

	room = ft_strsplit(str, ' ');
	check_room(room);
	if (!g_gen->rooms)
	{
		if (!(g_gen->n_rooms = (t_rooms *)ft_memalloc(sizeof(t_rooms))))
			my_exit(0);
		g_gen->n_rooms->prev = NULL;
		g_gen->n_rooms->next = NULL;
	}
	else if (g_gen->rooms)
	{
		end_room_lt = g_gen->n_rooms;
		check_duplication(end_room_lt, room);
		if (!(g_gen->n_rooms->next = (t_rooms *)ft_memalloc(sizeof(t_rooms))))
			my_exit(0);
		g_gen->n_rooms->next->prev = g_gen->n_rooms;
		g_gen->n_rooms = g_gen->n_rooms->next;
		g_gen->n_rooms->next = NULL;
	}
	parce_room2(room, a);
	g_gen->rooms++;
}
