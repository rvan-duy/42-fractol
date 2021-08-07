/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 19:28:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/08 19:37:19 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(n + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
