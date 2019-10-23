/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:11:04 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:11:05 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_FT_OTOOL_H
# define NM_OTOOL_FT_OTOOL_H
# include "global.h"

typedef enum	e_flags
{
	FLAG_t = 1 << 0,
	NO_FLAG = 1 << 1,
}				t_e_flag;

typedef enum	e_type
{
	IS_64 = 1 << 0,
	IS_32 = 1 << 1,
	IS_FAT = 1 << 2,
	IS_ERROR = 1 << 3
}				t_type;

typedef struct	s_otool
{
	char		buffer[75];
	void		*ptr;
	void		*fatptr;
	void		*end_ptr;
	char		*name;
	size_t		size;
	uint8_t		arg;
	uint8_t		type;
}				t_otool;

/*
** 32 bits
*/
void			handle_32(t_otool core);

/*
** 64 bits
*/
void			handle_64(t_otool core);
void			handle_fat(t_otool core);

/*
** Argument
*/

int				parse_arg(uint8_t *arg, int argc, char **argv);
int				parse_file(int i, int argc, char **argv, uint8_t arg);
/*
** otool
*/

int				otool(t_otool core);
int				core(char *name, uint8_t arg);
int				check_memory_file_otool(void *ptr, t_otool core);
int				otool_hex(long int nbr, char *bytes, unsigned int size);
bool			check_binary_l_cmd(size_t nb, t_l_cmd *lc, t_otool core);
bool			check_binary_l_seg64(size_t nb, t_sec64 *sect, t_otool core);
bool			check_binary_l_seg(size_t nb, t_sec *sect, t_otool core);

#endif
