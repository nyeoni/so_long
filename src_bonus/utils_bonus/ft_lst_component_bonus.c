/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_component_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:19:18 by nkim              #+#    #+#             */
/*   Updated: 2022/01/30 00:19:47 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_lstc_delete(t_component **lst, int x, int y)
{
	t_component	*tmp;
	t_component	*target;

	tmp = *lst;
	if (tmp && tmp->x == x && tmp->y == y)
	{
		*lst = tmp->next;
		free(tmp);
		tmp = NULL;
		return ;
	}
	while (tmp && tmp->next)
	{
		if (tmp->next->x == x && tmp->next->y == y)
		{
			target = tmp->next;
			tmp->next = tmp->next->next;
			free(target);
			target = NULL;
		}
		tmp = tmp->next;
	}
}

int	ft_lstc_add(t_component **lst, int x, int y)
{
	t_component	*new;

	new = (t_component *)malloc(sizeof(t_component));
	if (!new)
		return (0);
	new->x = x;
	new->y = y;
	new->next = NULL;
	ft_lstc_add_back(lst, new);
	return (1);
}
