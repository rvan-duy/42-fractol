/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 14:25:23 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/23 21:00:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t count, size_t size)
{
	void	*newptr;

	newptr = ft_calloc(count, size);
	if (newptr == NULL)
	{
		ft_free(&ptr);
		return (NULL);
	}
	ft_memcpy(newptr, ptr, count);
	ft_free(&ptr);
	return (newptr);
}
