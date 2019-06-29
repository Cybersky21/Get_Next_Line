/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:25 by acrooks           #+#    #+#             */
/*   Updated: 2019/05/23 22:29:21 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		find_string(char **str, char **line)
{
	char		*backn;
	char		*set;

	if (*str == NULL)
		return (0);
	backn = *str;
	if ((backn = ft_strchr(*str, '\n')))
	{
		*backn = '\0';
		if (!(*line = ft_strdup(*str)))
			return (-1);
		if (!(set = ft_strdup(backn + 1)))
			return (-1);
		free(*str);
		*str = set;
		return (1);
	}
	return (0);
}

static void		freestack(char **stack, char **buf)
{
	char		*tmp;

	if (!(tmp = ft_strjoin(*stack, *buf)))
		return ;
	free(*stack);
	*stack = tmp;
}

static int		readfile(int fd, char **buf, char **line, char **stack)
{
	int			ret;
	int			err;

	err = 0;
	while ((ret = read(fd, *buf, BUFF_SIZE)) > 0)
	{
		(*buf)[ret] = '\0';
		err = 0;
		if (*stack)
			freestack(stack, buf);
		else if (!(*stack = ft_strdup(*buf)))
			return (-1);
		if ((err = find_string(stack, line)))
			break ;
	}
	if (ret < BUFF_SIZE && err == 0)
	{
		*line = NULL;
		return (0);
	}
	return (ret == -1 ? -1 : 1);
}

static int		gnl(const int fd, char **line)
{
	char		*buf;
	int			ret;
	static char	*stack[MAX_FD + 1];

	ret = 0;
	stack[fd] == NULL ? stack[fd] = ft_strnew(1) : 0;
	if ((ret = find_string(&stack[fd], line)) == 0)
	{
		if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
		ret = readfile(fd, &buf, line, &stack[fd]);
		ft_strdel(&buf);
	}
	if (ret == 0)
		return (0);
	if (stack[fd] && stack[fd][0])
	{
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, buf, 0) == -1 || fd > MAX_FD)
		return (-1);
	i = gnl(fd, line);
	return (i);
}
