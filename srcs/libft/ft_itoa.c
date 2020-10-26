/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:23:31 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/13 14:01:13 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*ret;
	int				ret_len;
	long long int	temp;
	int				neg;
	long long int	num;

	neg = (n >= 0 ? 1 : -1);
	ret_len = 1 + (neg == -1 ? 1 : 0);
	num = (n >= 0 ? (long long int)n : -(long long int)n);
	temp = num;
	while ((temp /= 10) > 0)
		ret_len++;
	if (!(ret = (char*)malloc((ret_len + 1) * sizeof(char))))
		return (0);
	if (neg < 0)
		ret[0] = '-';
	ret[ret_len--] = 0;
	while (num >= 0 && ret_len >= 0)
	{
		if (neg < 0 && ret_len == 0)
			break ;
		ret[ret_len--] = num % 10 + '0';
		num /= 10;
	}
	return (ret);
}
