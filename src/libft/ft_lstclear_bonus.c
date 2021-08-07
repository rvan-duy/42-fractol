/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 12:24:59 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/03/04 14:44:04 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_lstdelone(tmp, *del);
		tmp = tmp2;
	}
	*lst = NULL;
}
