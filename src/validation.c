/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:11:46 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:11:48 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_room(char **room)
{
	int		i;
	int		a;

	i = 1;
	if (!room[0] || !room[1] || !room[2]
		|| room[0][0] == 'L' || room[0][0] == '#')
		my_exit(7);
	while (room[i])
	{
		a = 0;
		while (ft_isdigit(room[i][a]))
			a++;
		if (room[i][a] != '\0' || a > 5)
			my_exit(8);
		i++;
	}
	if (i != 3)
		my_exit(9);
}

void		check_duplication(t_rooms *rooms_lt, char **room)
{
	while (rooms_lt)
	{
		if (!room[0] || !room[1])
			my_exit(10);
		if ((ft_strcmp(rooms_lt->name, room[0]) == 0) ||
		(ft_strcmp(rooms_lt->x, room[1]) == 0
		&& ft_strcmp(rooms_lt->y, room[2]) == 0))
			my_exit(10);
		rooms_lt = rooms_lt->prev;
	}
}

static void	validation2(t_data *lt, int *i)
{
	if (*i == 0 && lt->data[0] != '#')
	{
		parce_ant(lt->data, 0);
		*i = 1;
	}
	else if (*i > 0 && *i < 3 && lt->data[0] != '#'
	&& ft_numbof_chars(lt->data, ' ') == 2)
	{
		parce_rooms(lt->data, 0);
		*i = 2;
	}
	else if (*i > 1 && *i < 4 && lt->data[0] != '#'
	&& ft_numbof_chars(lt->data, '-') == 1)
	{
		parce_way(lt->data);
		*i = 3;
	}
	else if (lt && lt->data && (lt->data[0] != '#' ||
	(lt->data[0] != '#' && lt->data[1] != '#')))
	{
		ft_printf("%s\n", lt->data);
		my_exit(6);
	}
}

static void	roll_to_end(t_data **lt)
{
	while ((*lt)->next && (*lt)->data[0] && (*lt)->data[1]
		&& (*lt)->data[0] == '#' && (*lt)->data[1] != '#')
		(*lt) = (*lt)->next;
}

void		validation(t_data *lt)
{
	int		i;

	i = 0;
	while (lt && lt->data)
	{
		roll_to_end(&lt);
		if (lt->data[0] == '#' && lt->data[1] == '#' &&
(ft_strcmp(lt->data, "##start") == 0 || ft_strcmp(lt->data, "##end") == 0))
		{
			if ((i < 0 || i > 2) && (ft_strcmp(lt->data, "##start") == 0 ||
			ft_strcmp(lt->data, "##end") == 0))
			{
				ft_printf("%s\n", lt->data);
				my_exit(6);
			}
			else if (ft_strcmp(lt->data, "##start") == 0)
				lt = parce_all(lt->next, 1);
			else if (ft_strcmp(lt->data, "##end") == 0)
				lt = parce_all(lt->next, 2);
			i = 2;
		}
		else
			validation2(lt, &i);
		lt = lt->next;
	}
}
