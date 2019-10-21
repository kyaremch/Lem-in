/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:10:00 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:10:01 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	bonus(int ac, char **argv, int i)
{
	if (argv[1] && ft_strcmp(argv[1], "--help") == 0)
		print_help();
	while (++i < ac)
	{
		if (argv[i] && ft_strcmp("-a", argv[i]) == 0)
			g_gen->ants = 1;
		else if (argv[i] && ft_strcmp("-w", argv[i]) == 0)
			g_gen->ways = 1;
		else if (argv[i] && ft_strcmp("-nom", argv[i]) == 0)
			g_gen->nom = 1;
		else if (argv[i] && ft_strcmp("-m", argv[i]) == 0)
			g_gen->no_moves = 1;
	}
}

int			main(int argc, char **argv)
{
	if (!(g_gen = (t_lt *)ft_memalloc(sizeof(t_lt))))
		my_exit(0);
	if (argc > 1)
		bonus(argc, argv, 0);
	read_map(-1);
	if (g_gen && g_gen->n_rooms)
		while (g_gen->n_rooms->prev != NULL)
			g_gen->n_rooms = g_gen->n_rooms->prev;
	print_map();
	if (check_input() == 0)
	{
		algo();
		if (g_gen->n_ways > 0)
			ants_go();
		else
		{
			ft_printf("%s\n", "ERROR");
			exit(1);
		}
	}
	if (g_gen->nom == 1)
		ft_printf("Number of moves - %d\n", g_gen->waves);
	print_bonus();
	return (0);
}
