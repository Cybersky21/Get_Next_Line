/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:00:47 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/08 19:00:47 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first(char const *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		else
			break ;
	}
	return (i);
}

static int	last(char const *s)
{
	int		i;
	int		end;

	if ((end = ft_strlen(s)) == 0)
		return (0);
	i = ft_strlen(s) - 1;
	if (!s)
		return (0);
	while (i > 0)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		else
			return (i);
	}
	return (end);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	size_t	j;
	size_t	len;
	char	*str;
	int		end;

	if (!s)
		return (NULL);
	i = first(s);
	j = 0;
	len = last(s) - first(s) + 1;
	end = last(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (s[i] && i <= end)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
