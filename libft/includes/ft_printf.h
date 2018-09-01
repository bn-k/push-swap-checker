/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:16:15 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/28 12:18:13 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "utf8.h"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# define PAD_ZERO (!body->point && body->zero)
# define PAD_SPACE (!body->zero || body->point)
# define SIGN ((!body->minus && (body->plus || body->space)) || body->minus)
# define FILL body->fill
# define POS(i) (i < 0 ? 0 : i)
# define HASH (body->sharp && (body->point && !body->fill))
# define BID 1000

extern char		g_trunk[BID];

typedef struct	s_total
{
	const char	*format;
	int			i;
	int			quanta;
	va_list		*ap;
}				t_total;

typedef struct	s_body
{
	int			len;
	char		minus;
	char		dash;
	char		space;
	char		apos;
	char		plus;
	char		zero;
	char		sharp;
	int			width;
	int			precis;
	char		point;
	int			fill;
	int			left;
	int			right;
	char		h;
	char		l;
	char		j;
	char		z;
	char		q;
}				t_body;

typedef struct	s_on_trunk
{
	char		code;
	int			(*t_func)(t_total*, t_body*);
}				t_on_trunk;

void			trunk(char *s, t_total *total, t_body *body);
void			trunk_unicode_wc(wchar_t *s, t_total *total, t_body *body);
void			trunk_unicode_ws(wchar_t *s, t_total *total, t_body *body);
void			trunk_unicode_left_distance(t_total *total, t_body *body);
void			trunk_unicode_right_distance(t_total *total, t_body *body);
void			trunk_integers(char *s, t_total *total, t_body *body);
void			trunk_o(char *s, t_total *total, t_body *body);
void			trunk_x(char *s, t_total *total, t_body *body);

void			test_1(void);
void			test_2(void);

int				ft_printf(const char *format, ...);
void			init_total(t_total *total, const char *format, va_list *ap);
void			charcat(char c, t_total *total);

int				isflag(int c);
int				is_modifier(char c);
void			body_parser(t_total *total, t_body *body);
void			flags(t_total *total, t_body *body);
void			width_and_precision(t_total *total, t_body *body);
void			modifier(t_total *total, t_body *body);

int				c_on_trunk(t_total *total, t_body *body);
int				wc_on_trunk(t_total *total, t_body *body);
int				s_on_trunk(t_total *total, t_body *body);
int				ws_on_trunk(t_total *total, t_body *body);
int				d_on_trunk(t_total *total, t_body *body);
int				o_on_trunk(t_total *tt, t_body *bd);
int				u_on_trunk(t_total *total, t_body *body);
int				x_on_trunk(t_total *tt, t_body *bd);
int				p_on_trunk(t_total *total, t_body *body);
int				no_on_trunk(t_total *total, t_body *body);
int				mod_on_trunk(t_total *total, t_body *body);

int				c_casted(char c, t_total *total, t_body *body);
int				s_casted(char *s, t_total *total, t_body *body);
int				wc_casted(wchar_t wc, t_total *total, t_body *body);
#endif
