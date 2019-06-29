/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:00:17 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/08 19:00:19 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = 0;
	j = len + start;
	if (!s)
		return (NULL);
	if (!((ft_strlen(s) - len) >= start))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start < j)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
