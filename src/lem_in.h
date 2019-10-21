/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:18:26 by kyaremch          #+#    #+#             */
/*   Updated: 2019/10/10 13:18:30 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct			s_rooms
{
	int					flag;
	struct s_rooms		*parent;
	struct s_print		*out_lt;
	int					status;
	struct s_rooms		*prev;
	char				*name;
	struct s_rooms		*next;
	char				*x;
	char				*y;
}						t_rooms;

typedef struct			s_lt
{
	t_rooms				*start_rm;
	int					n_ways_d;
	bool				no_moves;
	struct s_rooms		*n_rooms;
	struct s_ways		*n_ways;
	t_rooms				*end_rm;
	struct s_buf		*buffer;
	int					ants_d;
	int					a_run;
	int					a_out;
	int					rooms;
	int					waves;
	int					n_end;
	struct s_data		*data;
	bool				ants;
	int					ways;
	int					n_st;
	bool				nom;
}						t_lt;

typedef struct			s_data
{
	struct s_data		*next;
	char				*data;
}						t_data;

typedef struct			s_buf
{
	struct s_bfs		*bfs_buf;
	struct s_buf		*prev;
	struct s_buf		*next;
}						t_buf;

typedef struct			s_print
{
	t_rooms				*curr_room;
	t_rooms				*parent;
	t_rooms				*r_exit;
	struct s_print		*next;
}						t_print;

typedef struct			s_bfs
{
	t_rooms				*curr_room;
	t_rooms				*parent;
	struct s_bfs		*prev;
	struct s_bfs		*next;
}						t_bfs;

typedef struct			s_ways
{
	int					way_num;
	struct s_one_way	*one_w;
	struct s_ways		*prev;
	struct s_ways		*next;
	int					len;
	int					cap;
}						t_ways;

typedef struct			s_one_way
{
	struct s_one_way	*prev;
	int					n_lem;
	t_rooms				*room;
	struct s_one_way	*next;
}						t_one_way;

t_lt					*g_gen;
void					from_rom_to_room(t_one_way **path, int l, t_ways *ways);
void					help_s(t_rooms *fr_l, t_rooms *sr_l, t_print *sr_out);
void					help_f(t_rooms *fr_l, t_rooms *sr_l, t_print *fr_out);
void					parce_s(t_rooms *f_t, t_rooms *s_l, t_print *s_out);
void					parce_f(t_rooms *f_l, t_rooms *s_l, t_print *f_out);
void					check_duplication(t_rooms *rooms_lt, char **room);
int						ft_numbof_chars(char *str, char a);
void					parce_rooms(char *str, int a);
t_data					*parce_all(t_data *lt, int c);
void					parce_ant(char *str, int i);
void					save_pass(t_bfs *save_buff);
void					put_rooms_into_way(int i);
void					check_room(char **room);
void					validation(t_data *lt);
void					parce_way(char *str);
int						check_input(void);
void					print_bonus(void);
void					print_help(void);
void					print_map(void);
void					read_map(int i);
void					capacity(void);
void					skip_all(void);
void					my_exit(int n);
void					ants_go(void);
void					algo(void);

#endif
