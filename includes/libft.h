/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:58:34 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/11 14:47:26 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isspace(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strndup(char *str, int n);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putendl(char *s);
void			ft_putnbr(int n);

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list			*lst_new(void *content);
t_list			*lst_new_back(t_list **node, void *content);
void			lst_new_front(t_list **node, void *content);
void			lst_remove(t_list *node, void (*free_func)(void *));
void			lst_reverse(t_list **node);
size_t			lst_size(t_list *node);
void			lst_foreach(t_list *node, void (*func)(void *));
void			lst_clear(t_list **lst, void (*del)(void *));

#endif
