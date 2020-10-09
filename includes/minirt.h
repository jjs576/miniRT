/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/09 11:46:28 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "define.h"
# include "struct.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

int		open_file(t_file *file, char *filename);

int		parser(t_file *f, t_scene *s);


int		parse_resolution(char *str, t_scene *scene);
int		parse_ambient(char *str, t_scene *scene);
int		parse_camera(char *str, t_scene *scene);
int		parse_light(char *str, t_scene *scene);


int		parse_sphere(char *str, t_scene *scene);
int		parse_plane(char *str, t_scene *scene);
int		parse_square(char *str, t_scene *scene);
int		parse_cylinder(char *str, t_scene *scene);
int		parse_triangle(char *str, t_scene *scene);


double	parse_double(char *s, double *dst);
int		parse_multi_double(char	*s, double *dst);
int		parse_int(char *s, int *dst, int isSigned);
int		parse_multi_int(char *s, int *dst);
int		parse_space(char *s);


void	check_error(int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

t_list	*new_object(int type, void *object);
int		push_back(t_list **lst, int type, void *object);
t_list	*copy_list(t_list *lst);

void	ft_putchar(char c);
void	ft_putstr(char *s);

void	*ft_strndup(char *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
char	*ft_strjoin(char *dst, char *src);
int		ft_strchr(const char *s, int c);

#endif
