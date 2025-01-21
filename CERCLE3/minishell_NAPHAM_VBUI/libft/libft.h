/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napham <napham@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:20:41 by napham            #+#    #+#             */
/*   Updated: 2024/12/10 13:54:13 by napham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# ifndef FD_SIZE
#  define FD_SIZE 1
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_print_str(char *s);
int			ft_print_uint(unsigned int nbr);
int			ft_printpercent(void);
int			ft_putnum(unsigned long long n,
				unsigned int base, const char *digits);
int			ft_print_char(int c);
int			ft_print_dec(int nbr);
int			ft_print_hex_lower(unsigned int nbr);
int			ft_print_hex_upper(unsigned int nbr);
int			ft_print_ptr(void *ptr);
int			ft_formats(va_list args, const char format);
int			ft_printf(const char *str, ...);

int			ft_fprint_str(int fd, char *s);
int			ft_fprint_uint(int fd, unsigned int nbr);
int			ft_fprintpercent(int fd);
int			ft_fputnum(int fd, unsigned long long n, unsigned int base,
				const char *digits);
int			ft_fprint_char(int fd, int c);
int			ft_fprint_dec(int fd, int nbr);
int			ft_fprint_hex_lower(int fd, unsigned int nbr);
int			ft_fprint_hex_upper(int fd, unsigned int nbr);
int			ft_fprint_ptr(int fd, void *ptr);
int			ft_fformats(int fd, va_list args, const char format);
int			ft_fprintf(int fd, const char *str, ...);

double		ft_atof(char *str);
long int	ft_atol(const char *str);
int			ft_atoi(const char *str);
size_t		ft_nbrlen(long long n);
char		*ft_itoa(int n);

void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);

char		*ft_strnstr(char *big, char *little, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_tolower(int character);
int			ft_toupper(int character);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			char_is_separator(char c, char *charset);
int			count_words(char *str, char *charset);
void		write_word(char *dest, char *from, char *charset);
void		write_split(char **split, char *str, char *charset);
char		**ft_split_charset(char *str, char *charset);
size_t		ft_strlen(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strchr(const char *s, int c);
char		*ft_strchrset(char *str, char *charset);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(const char *s, char c);
size_t		ft_strlcat(char *s1, const char *s2, size_t n);
char		*ft_strlowcase(char *str);
char		*ft_strrchr(const char *s, int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strdup(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		ft_print_error(char *desc, int error);

void		ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr(char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnstr_fd(char *s, int fd, int n);
void		ft_putendl(char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);

int			ft_min(int a, int b);
int			ft_max(int a, int b);
double		ft_abs(double a);

int			ft_issign(char c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_isspace(int c);
int			ft_str_isalnum(char *str);

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);

void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstadd_front(t_list **lst, t_list *newlst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstadd_back(t_list **lst, t_list *newlst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);

char		*get_next_line(int fd);

#endif
