/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:52:17 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/20 14:10:59 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_stock_par
{
	int				size_param;
	char			*str;
	char			*copy;
	char			**tab;
}					t_stock_par;
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_charcat(char *s1, const char s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
size_t				ft_atoul(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
int					ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(int n);
char				*ft_stoa(short n);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
int					ft_isspace(int c);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t size);
int					ft_isnegative(int *n);
char				*ft_itoa_base(int n, int base);
char				*ft_ltoa_base(long n, int base);
char				*ft_lltoa_base(long long n, int base);
char				*ft_strlowcase(char *str);
char				*ft_ulltoa_base(unsigned long long n, int base);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
char				*ft_strjoinfree(char *s1, char *s2, size_t tofree);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_toupper(int c);
bool				ft_isupper(char c);
bool				ft_islower(char c);
#endif
