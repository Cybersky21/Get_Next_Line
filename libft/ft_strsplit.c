/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:01:00 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/08 19:01:01 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**clean(char **str, int i)
{
	while (i >= 0)
	{
		ft_strdel(&str[i]);
		i--;
	}
	ft_strdel(str);
	return (NULL);
}

static char		**words(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**str;

	if (!(str = (char **)malloc(sizeof(char *) * (ft_cntwrds(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s != c && *s)
			{
				s++;
				len++;
			}
			if (!(str[i] = ft_strnew(len)))
				return (clean(str, i));
			ft_strncpy(str[i++], --s - len + 1, len);
		}
		s++;
	}
	str[i] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = words(s, c);
	return (str);
}
