/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:39 by acrooks           #+#    #+#             */
/*   Updated: 2018/12/18 22:01:39 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# define MAX_FD 4864

# include <fcntl.h>
# include "libft/libft.h"

# if (BUFF_SIZE <= 0)
#  error BUFF_SIZE must be > 0
# endif

int		get_next_line(const int fd, char **line);

#endif
