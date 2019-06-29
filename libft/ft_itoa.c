/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:01:09 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/08 19:01:10 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != '\0')
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	f;
	size_t	i;

	i = length(n);
	f = 0;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		f = 1;
	}
	while (i-- > f)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
