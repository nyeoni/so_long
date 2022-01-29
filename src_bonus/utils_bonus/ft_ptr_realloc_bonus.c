/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:10:03 by nkim              #+#    #+#             */
/*   Updated: 2022/01/29 23:53:41 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_ptr_realloc(void *buf, int before_size, int after_size)
{
	int		idx;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
	idx = 0;
	while (idx < before_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	free(buf);
	return ((void *)dst);
}
