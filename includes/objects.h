/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:53:00 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/10 17:54:57 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct	s_sphere
{
	double	center[3];
	double	diameter;
	int		color[3];
}				t_sphere;

typedef struct	s_plane
{
	double	point[3];
	double	axis[3];
	int		color[3];
}				t_plane;

typedef struct	s_square
{
	double	center[3];
	double	axis[3];
	double	size;
	int		color[3];
}				t_square;

typedef struct	s_cylinder
{
	double	point[3];
	double	axis[3];
	double	diameter;
	double	height;
	int		color[3];
}				t_cylinder;

typedef struct	s_triangle
{
	double	point[3][3];
	int		color[3];
}				t_triangle;

#endif
