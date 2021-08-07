/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array_len.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 15:53:03 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/21 23:34:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

size_t	ft_array_len(void **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
