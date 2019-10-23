/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:11:06 by bnoufel           #+#    #+#             */
/*   Updated: 2019/10/07 10:11:07 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_GLOBAL_H
# define NM_OTOOL_GLOBAL_H
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <errno.h>
# define PROT PROT_READ
# define MAP MAP_PRIVATE

typedef struct stat						t_stat;
typedef struct load_command				t_l_cmd;
typedef struct symtab_command			t_s_cmd;
/*
** Archive
*/

typedef struct ar_hdr					t_ar;
/*
** 32 bits
*/
typedef struct mach_header				t_mh;
typedef struct segment_command			t_sc;
typedef struct nlist					t_nlst;
typedef struct section					t_sec;
/*
** Fat
*/
typedef struct fat_header				t_fh;
typedef struct fat_arch					t_fharch;

/*
** 64 bits
*/
typedef struct mach_header_64			t_mh64;
typedef struct segment_command_64		t_sc64;
typedef struct nlist_64					t_nlst_64;
typedef struct section_64				t_sec64;
/*
** Fat
*/
typedef struct fat_header_64			t_fh64;
typedef struct fat_arch_64				t_fharch64;

void									ft_munmap(void *ptr, size_t size);
void									mmap_err_alloc(char *name);
#endif
