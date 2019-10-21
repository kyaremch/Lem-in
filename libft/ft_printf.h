/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaremch <kyaremch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:09:40 by kyaremch          #+#    #+#             */
/*   Updated: 2019/03/25 12:09:48 by kyaremch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# define BUFF_SIZE 100

typedef struct	s_node
{
	char		rez[2048];
	int			i;
	int			it;
	int			int_rez;
}				t_node;

typedef struct	s_fl
{
	int			flag_m;
	int			flag_h;
	int			flag_a;
	int			flag_alen;
	int			flag_z;
	int			flag_s;
	int			flag_p;
	int			width;
	char		sign[3];
	int			flag_fl;
	int			paste_or;
}				t_fl;

typedef struct	s_type
{
	int			flag_h;
	int			flag_hh;
	int			flag_l;
	int			flag_ll;
	int			flag_long;
	int			spec_un;
}				t_type;

t_node g_node;
t_fl g_fl;
t_type g_type;

void			minus_iter(int i);
long double		cust_float(va_list ap);
void			int_help(int *j, char *numb);
void			if_string(va_list ap);
void			if_char(va_list ap);
void			if_int(va_list ap);
void			if_unsigned(va_list ap);
void			spec_xocs(va_list ap, char form);
void			spec_unsigned_hash(int len, int j, char *numb, uintmax_t i);
void			flag_hash_for_spec(char *numb);
void			check_type(const char format);
void			width_move(int len);
uintmax_t		cust_unsigned(va_list ap);
intmax_t		cust_signed(va_list ap);
void			remuve_min(char *numb);
char			*ffloat(long double nb);
char			*ft_itoa_base(intmax_t nb, int base);
char			*ft_itoa_base_unsigned(uintmax_t nb, int base);
int				int_parth_positive(int len, int j);
void			int_parth_negative(int len, int j);
int				ft_printf(const char *format, ...);
void			write_in_buf(char c);
void			check_format(const char *format);
void			check_spec(va_list ap, char form);
char			*string_malloc(const char *string);
void			if_hash(char sign);

#endif
