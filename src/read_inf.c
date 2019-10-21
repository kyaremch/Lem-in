/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:11:38 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:11:39 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_map(int i)
{
	char	*line;
	t_data	*map;

	if (!(map = (t_data *)ft_memalloc(sizeof(t_data))))
		my_exit(0);
	g_gen->data = map;
	while (get_next_line(0, &line) > 0)
	{
		if (++i != 0)
		{
			if (!(map->next = (t_data *)ft_memalloc(sizeof(t_data))))
				my_exit(0);
			map = map->next;
		}
		map->data = line;
		map->next = NULL;
		if (ft_strcmp(line, "\0") == 0)
			break ;
	}
	validation(g_gen->data);
}
