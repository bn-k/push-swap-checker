/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:19:20 by abbenham          #+#    #+#             */
/*   Updated: 2018/06/28 12:23:17 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>

typedef struct		s_lst
{
	void			*data;
	struct s_lst	*next;
}					t_lst;

t_lst				*ft_lstnew(void *data);
int					ft_lstprintnb(t_lst *lst);
int					ft_lstprintstr(t_lst *lst);
int					deref(int *nb);
t_lst				*ft_lstlast(t_lst *lst);

void				ft_lstaddfront(t_lst **alst, t_lst *node);
void				ft_lstaddback(t_lst **alst, t_lst *node);
void				ft_lstaddafter(t_lst *lst, t_lst *node);
void				ft_lstadditer(t_lst **begin, t_lst **iterator, t_lst *node);
void				ft_lstaddby(t_lst **alst, t_lst *node,
							int (*cmp)(const void *data1, const void *data2));

t_lst				*ft_lstpushfront(t_lst **alst, void *data);
t_lst				*ft_lstpushback(t_lst **alst, void *data);
t_lst				*ft_lstpushafter(t_lst *lst, void *data);
t_lst				*ft_lstpushiter(t_lst **begin, t_lst **iterator,
							void *data);
t_lst				*ft_lstpushby(t_lst **alst, void *data,
							int (*cmp)(const void *data1, const void *data2));

t_lst				*ft_lstdup(t_lst *lst);
t_lst				*ft_lstmap(t_lst *lst, t_lst *(*f)(t_lst *node));
t_lst				*ft_lstremback(t_lst **alst);

void				ft_lstdel(t_lst **alst, void (*del)(void *data));
void				ft_lstshift(t_lst **alst, void (*del)(void *data));
void				ft_lstdelback(t_lst **alst, void (*del)(void *data));

int					ft_lstlen(t_lst *lst);
void				ft_lstiter(t_lst *lst, void (*f)(t_lst *node));
void				*ft_lstfold(t_lst *lst,
							void *(*f)(const void *data1, const void *data2));

t_lst				*ft_lstgetn(t_lst *lst, int index);

void				**ft_lsttoarray(t_lst *lst);

t_lst				*ft_arraytolst(void **arr);
t_lst				*ft_strsplit_tolst(const char *s, char c);

t_lst				*ft_lstnew__(size_t size);
t_lst				*ft_lstpushfront__(size_t size, t_lst **alst);
t_lst				*ft_lstpushback__(size_t size, t_lst **alst);

#endif
