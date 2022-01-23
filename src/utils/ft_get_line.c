/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:18:37 by nkim              #+#    #+#             */
/*   Updated: 2022/01/23 19:06:24 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_get_line(int fd) {
	char *line;
	char eol;
	int len;

	line = get_next_line(fd);
	if (!line)
		return NULL;
	len = ft_strlen(line);
	eol = line[len - 1];
	if (eol == '\n')
		line[len - 1] = 0;
	return line;
}