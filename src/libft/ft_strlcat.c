/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ruben <rvan-duy@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 10:55:10 by ruben         #+#    #+#                 */
/*   Updated: 2021/02/12 14:16:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	destsize;
	size_t	i;

	destsize = 0;
	i = 0;
	while (dst[destsize] && destsize < n)
		destsize++;
	while ((destsize + i + 1) < n && src[i] != '\0')
	{
		dst[destsize + i] = src[i];
		i++;
	}
	if (destsize < n)
		dst[destsize + i] = '\0';
	return (destsize + ft_strlen(src));
}
