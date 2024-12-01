/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbui <vbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:37:32 by vbui              #+#    #+#             */
/*   Updated: 2023/11/24 20:19:42 by vbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include "../home/vbui/Documents/PROJECTS42/libft/libft.h"
# include <stdarg.h>
# include <stddef.h>

typedef enum		e_var
{
			DEF, H, HH, L, LL, J, Z, T
}				t_var;

typedef structs_	struct
{
	char				type;
	char				flag[5];
	char				nega;
	int					oct;
	int					err;
	va_list				ap;
	t_var				size;
	intmax_t			prec;
	int					width;
	intmax_t			arg;
	char				*s_arg;
	wchar_t				*ws_arg;
	intmax_t			l_arg;
	char				bad_c;
}				t_struct;

int				ft_printf(char *txt, ...);
char			*ft_parse_and_store(t_struct *strt, char *format);
void			ft_initialise(t_struct *strt);
void			ft_get_arg(t_struct *strt);
void			ft_strjoinfree(char *s1, char *s2, t_struct *strt, int n);
void			ft_wstrjoinfree(wchar_t *s1, wchar_t *s2,
					t_struct *strt, int n);
void			ft_for_s(t_struct *strt);
void			ft_for_p(t_struct *strt);
void			ft_for_d_and_i(t_struct *strt);
void			ft_for_o(t_struct *strt);
void			ft_for_u(t_struct *strt);
void			ft_for_x(t_struct *strt);
void			ft_for_c(t_struct *strt);
void			ft_for_pct(t_struct *strt);
void			ft_first(t_struct *strt);
void			ft_bad_parse(t_struct *strt, char *format);

#endif