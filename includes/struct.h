/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:11:11 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:11:14 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_STRUCT_H
# define NM_OTOOL_STRUCT_H
# include "global.h"

typedef struct							s_cont
{
	char						symbol;
	char						*value;
	char						*name;
	bool						print;
}										t_cont;

typedef struct							s_l
{
	t_cont						data;
	struct s_l					*next;
	struct s_l					*prev;
	struct s_l					*head;
}										t_l;

typedef struct							s_handle
{
	t_nlst_64					*symoff;
	t_nlst						*symoff32;
	char						*strtable;
	char						*name;
	size_t						size_name;
	t_cont						cont;
	struct s_segment			*segment;
	t_l							*list;
}										t_h;

typedef struct							s_segment
{
	int							index;
	int							text;
	int							data;
	int							bss;
}										t_segment;

typedef struct							s_nm
{
	uint64_t					size;
	uint8_t						index;
	char						*name;
	size_t						big_n_strx_val;
	void						*ptr;
	void						*end_ptr;
	t_l							*list;
	struct s_nm					*next;
	struct s_nm					*head;
	uint32_t					arg;
	uint8_t						type;
	bool						is_fat;
	t_h							*s;
}										t_nm;

typedef struct							s_core
{
	char						*name;
	uint32_t					arg;
	uint8_t						index;
}										t_core;

typedef enum							e_flags
{
	FLAG_g = 1 << 0,
	FLAG_p = 1 << 1,
	FLAG_u = 1 << 2,
	FLAG_U = 1 << 3,
	FLAG_j = 1 << 4,
	FLAG_A = 1 << 5,
	FLAG_r = 1 << 6,
	NO_FLAG = 1 << 7,
	C_FLAG = 1 << 8
}										t_e_flag;
typedef enum							e_type
{
	IS_64 = 1 << 0,
	IS_32 = 1 << 1,
	IS_FAT = 1 << 2,
	IS_FAT64 = 1 << 3,
	IS_ERROR = 1 << 4
}										t_type;

typedef struct							s_tmp_lst
{
	int							size;
	t_core						core;
	void						*ptr;
}										t_tmp_lst;

#endif
