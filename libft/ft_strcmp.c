/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:31:46 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/07 13:31:47 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i]) || (s1[i] && s2[i] == '\0'))
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
