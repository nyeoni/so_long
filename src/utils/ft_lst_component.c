/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_component.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:19:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/26 16:57:51 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_component	*ft_lstc_last(t_component *component)
{
	if (!component)
		return (0);
	while (component->next)
		component = component->next;
	return (component);
}

void	ft_lstc_add_back(t_component **lst, t_component *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstc_last(*lst)->next = new;
}

t_component	*ft_lstc_new(int x, int y)
{
	t_component	*res;

	res = (t_component *)malloc(sizeof(t_component));
	if (!res)
		return (0);
	res->x = x;
	res->y = y;
	res->next = NULL;
	return (res);
}

int	ft_lstc_size(t_component *lst)
{
	int	cnt;

	if (!lst)
		return (0);
	cnt = 1;
	while (lst->next)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

void ft_lstc_add(t_component **lst, int x, int y)
{
	t_component *new;

	new = ft_lstc_new(x, y);
	ft_lstc_add_back(lst, new);
}