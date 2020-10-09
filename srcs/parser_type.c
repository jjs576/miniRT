/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:59:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/09 11:54:04 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	parse_double(char *s, double *dst)
{
	double	n;
	int		decimal;
	int		fraction;
	int		count;

	count = 0;
	decimal = 0;
	fraction = 0;
	count += parse_int(s + count, &decimal, TRUE);
	if (*(s + count) == '.')
	{
		count++;
		count += parse_int(s + count, &fraction, FALSE);
	}
	n = decimal + (pow(0.1, floor(log10(fraction) + 1)) * fraction);
	*dst = n;
	return (count);
}

int		parse_multi_double(char	*s, double *dst)
{
	int		count;

	count = 0;
	count += parse_double(s + count, dst[0]);
	if (*(s + count) == ',')
		count++;
	else
		return (-1);
	count += parse_double(s + count, dst[1]);
	if (*(s + count) == ',')
		count++;
	else
		return (-1);
	count += parse_double(s + count, dst[2]);
	return (count);

}

int		parse_int(char *s, int *dst, int isSigned)
{
	long long	n;
	int			negative;
	int			count;

	count = 0;
	n = 0;
	negative = 1;
	while (*(s + count))
	{
		if (*s >= '0' && *s <= '9')
			n = n * 10 + *(s + count) - '0';
		else if (isSigned && *(s + count) == '-')
			negative = -1;
		else if (ft_strchr(",. \t\r\f\v\n", *(s + count)) != -1)
			break ;
		else
			check_error(E_PARSE_FAIL);
		count++;
	}
	*dst = (int)(n * negative);
	return (count);
}

int		parse_multi_int(char *s, int *dst)
{
	int		count;

	count = 0;
	count += parse_int(s + count, dst[0], TRUE);
	if (*(s + count) == ',')
		count++;
	else
		return (-1);
	count += parse_int(s + count, dst[1], TRUE);
	if (*(s + count) == ',')
		count++;
	else
		return (-1);
	count += parse_int(s + count, dst[2], TRUE);
	return (count);
}

int		parse_space(char *s)
{
	int	count;

	count = 0;
	while (ft_strchr(" \t\r\f\v", *(s + count) > -1)
		count++;
	return (count);
}
