/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/07 20:47:49 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "define.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define RETURN_SUCCESS		1
# define RETURN_FAIL		0

typedef struct	s_file
{
	char	*name;
	int		fd;
	int		length;
	char	*data;
}				t_file;

typedef struct	s_rt
{
	
}				t_rt;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;	
}				t_mlx;

int				open_file(t_file *file, char *filename);


void			check_error(int n);

void			ft_putchar(char c);
void			ft_putstr(char *s);

int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *s);
char			*ft_strjoin(char *dst, char *src);

#endif
