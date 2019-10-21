/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:11:15 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:11:16 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_help(void)
{
	ft_printf("INSTRUCTION:\nflag \"-a\" - show you number of ants\n");
	ft_printf("flag \"-w\" - show you possible ways\n");
	ft_printf("flag \"-c\" - show colorized info\n");
	ft_printf("flag \"-e\" - active error manager\n");
	ft_printf("flag \"-nom\" - show nomber of moves\n");
	ft_printf("flag \"-p\" - disable moves\n");
	exit(0);
}

int			check_input(void)
{
	if (g_gen->n_st == 0 || g_gen->n_end == 0
	|| g_gen->ants_d < 1 || g_gen->ants_d > 1000000)
	{
		ft_printf("%s\n", "No enough input data");
		exit(1);
	}
	return (0);
}

static void	my_exit2(int n)
{
	if (n == 10)
		ft_printf("%s\n", "Duplicate input data");
	if (n == 8)
		ft_printf("%s\n", "Wrong coordinate`s");
	if (n == 9)
		ft_printf("%s\n", "Too much coordinate`s");
	if (n == 6)
		ft_printf("%s\n", "Wrong input data");
	if (n == 7)
		ft_printf("%s\n", "Wrong room name");
	if (n == 3)
		ft_printf("%s\n", "Double command");
	if (n == 4)
		ft_printf("%s\n", "Wrong number of room`s when connection set");
	if (n == 5)
		ft_printf("%s\n", "Wrong room name when connection set");
	if (n == 1)
		ft_printf("%s\n", "Incorrect input of ants");
	if (n == 2)
		ft_printf("%s\n", "Number of ants < 1");
	if (n == 0)
		ft_printf("%s\n", "Memory error");
}

void		my_exit(int n)
{
	if (check_input() == 0 && g_gen && g_gen->n_rooms && n != 6)
	{
		algo();
		if (g_gen->n_ways > 0)
			ants_go();
		else
			my_exit2(n);
	}
	else
	{
		algo();
		if (g_gen->n_ways > 0)
			ants_go();
		my_exit2(n);
	}
	exit(1);
}
