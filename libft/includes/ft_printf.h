/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:39:33 by jthiew            #+#    #+#             */
/*   Updated: 2025/02/12 17:09:13 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef SPECS
#  define SPECS "cspdiuxX%"
# endif

# ifndef FLAGS
#  define FLAGS "-0.*# +"
# endif

typedef struct s_flags
{
	int	left;
	int	zero;
	int	precision;
	int	star;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	spec;
}	t_flags;

// ft_printf
int		ft_parse_flags(const char *str, int i, va_list args, t_flags *flags);
int		ft_parse_specs(char c, va_list args, t_flags flags);
int		ft_parse_str(const char *str, va_list args);
int		ft_printf(const char *format, ...);

// ft_flags_utils_1
t_flags	ft_init_flags(void);
t_flags	ft_flag_left(t_flags flags);
int		ft_flag_precision(const char *str, int i, va_list args, t_flags *flags);
t_flags	ft_flag_width(t_flags flag, va_list args);
void	ft_flag_digit(char c, t_flags *flags);

// ft_flags_utils_2
int		ft_pad_width(int width, int len, int zero);

// ft_print_c
int		ft_print_char(char c);
int		ft_print_c(char c, t_flags flags);

// ft_print_s
int		ft_print_string_pre(char *s, t_flags flags);
int		ft_print_s(char *s, t_flags flags);

// ft_print_d
int		ft_print_d_sign(int d, t_flags flags);
int		ft_print_d_logic_pres(char *nbr_str, int nbr_len, int d, t_flags flags);
int		ft_print_d_logic(char *nbr_str, int nbr_len, int d, t_flags flags);
void	ft_print_d_fmt_flags(int d, int nbr_len, t_flags *flags);
int		ft_print_d(int d, t_flags flags);

// ft_print_d_1
char	*ft_print_d_itoa(int d);

// ft_print_u
int		ft_print_u_logic_pres(char *nbr_str, int nbr_len, t_flags flags);
int		ft_print_u_logic(char *nbr_str, int nbr_len, t_flags flags);
void	ft_print_u_fmt_flags(int nbr_len, t_flags *flags);
int		ft_print_u(unsigned int d, t_flags flags);

// ft_print_u_1
char	*ft_print_u_strrev(char *s, int ind);
char	*ft_print_u_utoa(unsigned int d);

// ft_print_p
int		ft_print_p_logic(unsigned long p, char *adr_str, int adr_len);
char	*ft_print_p_strrev(char *s, int ind);
int		ft_print_p_adr_len(unsigned long p);
char	*ft_print_p_adr_str(unsigned long p);
int		ft_print_p(unsigned long p, t_flags flags);

// ft_print_x
int		ft_print_x_logic_p(char *nbr_str, int nbr_len, int caps, t_flags flags);
int		ft_print_x_logic(char *nbr_str, int nbr_len, int caps, t_flags flags);
void	ft_print_x_fmt_flags(int nbr_len, unsigned int d, t_flags *flags);
int		ft_print_x(unsigned int d, int caps, t_flags flags);

//ft_print_x_1
int		ft_print_x_hash(int caps, t_flags flags);
char	*ft_print_x_str(unsigned int d, int len, int caps);
char	*ft_print_x_strrev(char *s, int len);
char	*ft_print_x_xtoa(unsigned int d, int caps);

#endif
