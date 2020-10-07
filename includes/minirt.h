/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/07 22:00:13 by jjoo             ###   ########.fr       */
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

int				open_file(t_file *file, char *filename);


void			check_error(int n);

void			ft_putchar(char c);
void			ft_putstr(char *s);

int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *s);
char			*ft_strjoin(char *dst, char *src);

#endif
