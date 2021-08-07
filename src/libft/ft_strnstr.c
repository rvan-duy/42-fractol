/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ruben <rvan-duy@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 16:17:43 by ruben         #+#    #+#                 */
/*   Updated: 2020/11/07 14:16:38 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char			*haystack;
	char			*needle;

	i = 0;
	haystack = (char *)s1;
	needle = (char *)s2;
	if (needle[i] == '\0')
		return (haystack);
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		while (haystack[i + j] == needle[0 + j])
		{
			if (needle[0 + j + 1] == '\0' && i + j < n)
				return (&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
