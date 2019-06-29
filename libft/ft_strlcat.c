/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:40:05 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/06 16:40:06 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*ddst;
	const char	*ssrc;
	size_t		i;
	size_t		len;

	ddst = dst;
	ssrc = src;
	i = size;
	while (i-- != 0 && *dst != '\0')
		dst++;
	len = dst - ddst;
	i = size - len;
	if (i-- == 0)
		return (len + ft_strlen(src));
	while (*src != '\0')
	{
		if (i != 0)
		{
			*dst++ = *src;
			i--;
		}
		src++;
	}
	*dst = '\0';
	return (len + (src - ssrc));
}
