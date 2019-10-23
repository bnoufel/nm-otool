/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:11:01 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:11:03 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_FT_NM_H
# define NM_OTOOL_FT_NM_H
# include "global.h"
# include "struct.h"

/*
** 32 bits
*/

bool		handle_32(t_nm **p_list);
char		*get_value_32(t_h *s, int i, t_mh *h);
char		*get_value_if_null_32(void);
bool		handle_fat(t_nm **p_list);
bool		put_print_handle_32(t_nm **p_l, t_s_cmd *sym, t_mh *h, int i);
void		putlcseg_32(t_nm **p_list, t_sec *sect);

/*
** 64 bits
*/

bool		handle_64(t_nm **p_list);
char		*get_value_64(uint64_t n_v, t_mh64 *h);
char		*get_value_if_null_64(void);
bool		check_memory_file(void *ptr, t_nm **l);
bool		handle_fat64(t_nm **p_list);
bool		put_print_handle_64(t_nm **p_l, t_s_cmd *sym, t_mh64 *h, int i);
void		putlcseg_64(t_nm **p_list, t_sec64 *s);

/*
** Lists
*/

void		build_list(t_l **list, t_cont cont);
void		init_list_nm(t_nm **p_list, int size, t_core core, void *ptr);
int			display_p_list(t_nm *p_list);

/*
** sort
*/
void		merge_sort(t_l **list);
void		merge2(t_l **result, t_l **left, t_l **right);

/*
** rsort
*/

void		rmerge_sort(t_l **list);
void		rmerge2(t_l **result, t_l **left, t_l **right);
/*
** Argument
*/

int			parse_arg(uint32_t *arg, int argc, char **argv);
void		no_more_defined(char c, int *ret);
void		help(char c);
int			ret_parse_arg(uint32_t *arg, int32_t ret, int32_t i);

/*
** nm
*/

void		malloc_failed(char *name);
int			core(char *name, t_nm **p_list, uint32_t arg, uint8_t index);
int			nm(t_nm **p_list);
void		reset_section(t_nm **p_list);
size_t		get_size_name(uint32_t stroff, t_nm **p_l);
void		ft_byebye(t_nm *p_list);
bool		err_nm(t_nm *lst, bool malformed);
char		*putnamesymbol(char *str, char symbol);
bool		handle_no_cmds(uint32_t i, uint32_t ncmds, t_nm *p_l);
#endif
