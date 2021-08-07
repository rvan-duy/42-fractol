/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 12:52:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/03/04 14:44:10 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (tmp)
		ft_lstlast(tmp)->next = new;
	else
		ft_lstadd_front(lst, new);
}
