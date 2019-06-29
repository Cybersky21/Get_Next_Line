/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:31:01 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/06 13:31:02 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*chr;

	i = 0;
	chr = (unsigned char *)s;
	while (i < n)
	{
		if (chr[i] == (unsigned char)c)
			return (&chr[i]);
		i++;
	}
	return (NULL);
}
