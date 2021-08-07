/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_append.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/08 19:01:40 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/20 18:21:24 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Be carefull about the NULL return, you might need to free additional stuff
char	*ft_append(char *dst, const char *src)
{
	size_t	len1;
	size_t	len2;
	char	*newstr;

	if (!dst || !src)
		return (NULL);
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	newstr = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, dst, len1);
	ft_memcpy(newstr + len1, src, len2);
	free(dst);
	return (newstr);
}
