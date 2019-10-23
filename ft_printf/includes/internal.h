/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:28:33 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:28:36 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERNAL_H
# define __INTERNAL_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# define ERROR	-1
# define BUFFER_SIZE 4096

/*
** uc flag
** + == 1
** - == 2
** ' ' == 4
** 0 == 8
** # == 16
** dot exist == 32
*/

/*
** uc modifier
** hh == 1
** ll  == 2
** h  == 4
** l  == 8
** j  == 16
** z  == 32
*/

/*
** short type
** s == 1
** S == 2
** p == 4
** d == 8
** o == 16
** u == 32
** x == 64
** X == 128
** c == 256
** C == 512
** % == 1024
*/

/*
** preci_padding
** first * == 1
** second * == 2
*/
typedef struct				s_var
{
	void					*ptr;
	double					coma;
	float					dot;
	int64_t					value;
	uint64_t				uvalue;
}							t_var;

typedef struct				s_core
{
	char					buffer[BUFFER_SIZE];
	size_t					padding;
	size_t					precision;
	char					prefix[3];
	int						fd;
	u_int8_t				flags;
	u_int8_t				modifier;
	u_int8_t				star_preci;
	u_int8_t				star_padd;
	int16_t					type;
	t_var					var;
	int						count;
	int						count_big_s;
	int						index;
}							t_core;

typedef struct				s_four
{
	u_int8_t				one;
	u_int8_t				two;
	u_int8_t				three;
	u_int8_t				four;
}							t_four;

typedef union				u_f
{
	unsigned int			value;
	t_four					four;
}							t_f;

typedef	struct				s_tmp
{
	const char				*str;
	int						tmp;
	size_t					jump;
	int						*i;
}							t_tmp;
void						ft_init_struct(t_core *core, int fd);
void						ft_core(t_core *core, const char *str,
							int fd, va_list ap);
void						ft_reset_buffer(t_core *core,
							size_t len, char c, char *str);
bool						ft_check_if_zero_n_dot(t_core *core);
void						ft_flag(const char *str, int *i, t_core *core);
void						ft_precision(const char *str, int *i, t_core *core);
void						ft_modifier(const char *str, int *i, t_core *core);
void						ft_types(const char *str, int *i, t_core *core);
void						ft_convert(t_core *core, va_list ap);
void						ft_convert_s(t_core *core);
bool						ft_putzero(t_core *core);
void						ft_convert_d(t_core *core);
void						ft_flag_padding_preci(t_core *c, char *s, int neg);
void						ft_put_in_buffer(t_core *core, char *str);
void						ft_prefix(t_core *core, int neg);
bool						ft_put_zero_space(int neg, int padd,
							char *str, t_core *core);
int							ft_get_precision(t_core *core, char *str);
void						ft_convert_perc(t_core *core);
void						ft_convert_p(t_core *core);
void						ft_convert_big_c(t_core *core);
void						ft_convert_big_s(t_core *core);
int							ft_unicode(t_core *core, t_f *u, int v, int *ret);
void						ft_display_zero(t_core *core);
void						ft_convert_c(t_core *core);
void						ft_convert_o(t_core *core);
void						ft_convert_x(t_core *core);
void						ft_convert_u(t_core *core);
void						ft_convert_b(t_core *core);
void						ft_convert_r(t_core *core);
void						ft_convert_big_r(t_core *core);
void						ft_convert_big_x(t_core *core);
int							ft_count_special(int value);
void						ft_put_null_in_buffer(t_core *core);

void						ft_prefix_d(t_core *core, int neg, size_t len);
void						ft_prefix_x(t_core *core);
void						ft_put_d(t_core *core, char *str, int neg);
void						ft_put_x(t_core *core, char *str, int neg);
void						ft_strcatindex(t_core *c, const char *s, size_t l);
void						ft_charcatindex(t_core *core, const char str);
void						ft_putbuff_s(t_core *core, char *str);
void						ft_assign2(t_core *core);
void						ft_unicode2(int *n, int nb_bit, t_f *u, int value);
void						ft_display(t_f *unicode, t_core *core);
bool						ft_invalid(int unicode);
int							ft_unicode3(t_f *unicode, int value);
#endif
