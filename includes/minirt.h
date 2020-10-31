/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 19:09:15 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>

# include "libft.h"
# include "mlx.h"

# define MAX_OBJECT			1024

# define TRUE				1
# define FALSE				0

# define R_GNL_ERROR		-1
# define R_GNL_EOF			0
# define R_GNL_LINE			1

# define E_ARGUMENTS		-1
# define E_CANNOT_OPEN		-2
# define E_WRONG_FILENAME	-3
# define E_CANNOT_READ		-4
# define E_INVALID_FILE		-5
# define E_MALLOC_FAIL		-6
# define E_CANNOT_PARSE		-7

# define E_MSG				"Error - "
# define E_ARGUMENTS_MSG		"invalid arguments\n"
# define E_CANNOT_OPEN_MSG	"can't open file\n"
# define E_CANNOT_READ_MSG	"can't read file\n"
# define E_CANNOT_PARSE_MSG	"can't parse\n"

# define T_AMBIENT			1 << 0
# define T_LIGHT			1 << 1
# define T_CAMERA			1 << 2

# define T_SPHERE			1 << 3
# define T_PLANE			1 << 4
# define T_SQUARE			1 << 5
# define T_CYLINDER			1 << 6
# define T_TRIANGLE			1 << 7

void		print_error(int errno);

#endif
