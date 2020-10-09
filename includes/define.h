/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:18:08 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/09 11:24:46 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define BUF_SIZE			1024

# define TRUE				1
# define FALSE				0

# define E_ARGUMENTS		-1
# define E_CANNOT_OPEN		-2
# define E_WRONG_FILENAME	-3
# define E_CANNOT_READ		-4
# define E_INVALID_FILE		-5
# define E_MALLOC_FAIL		-6
# define E_PARSE_FAIL		-7

# define T_SPHERE			0
# define T_PLANE			1
# define T_SQUARE			2
# define T_CYLINDER			3
# define T_TRIANGLE			4
# define T_LIGHT			5
# define T_CAMERA			6

#endif
