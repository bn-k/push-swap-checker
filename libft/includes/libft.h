/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbenham <newcratie@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:14:01 by abbenham          #+#    #+#             */
/*   Updated: 2018/08/17 16:03:10 by abbenham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ft_printf.h>
# include <list.h>
# include <limits.h>
# include "utf8.h"

char			**tabcat(char **tab, char *ptr, int new_size);
size_t			ft_nbrlen(int long long nb);
size_t			ft_nbrlen_iull(unsigned long long nb);
size_t			ft_nbrlen_base(unsigned long long nb, unsigned int lenbase);
int				ft_atoi(const char *str);
long			ft_atoi_long(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_iull(unsigned long long n);
char			*ft_itoa_base(unsigned long long n, char *base);

void			ft_putnbrl(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_ill(int long long nb);
void			ft_putnbr_iull(int unsigned long long n);
void			ft_putnbr(int n);
void			ft_putnuminfo(int nb, char *spec);
size_t			ft_putnbr_base(unsigned long long nbr, char *base);

size_t			ft_print_adress(long unsigned int nbr);
void			ft_create_elem(void *data);
void			ft_swap(int *a, int *b);
int				ft_strlen(const char *str);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_tablen(void **tab);
void			ft_freetab(void **tab, int size);

size_t			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strdup(char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_isalnum(int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,\
				size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrev(char *str);
size_t			ft_strnlen(const char *s, size_t maxlen);
int				ft_megalen(int argc, char **argv);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_display_file(char *str, int to_close);

int				ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
int				ft_tolower(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);

int				str_isdigit(char *s);

#endif
