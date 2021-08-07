/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 17:14:53 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/15 11:50:28 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*newstr;

	i = 0;
	if (!s || !len)
		return (ft_strdup(""));
	strlen = ft_strlen(s);
	if (start > strlen)
		return (ft_strdup(""));
	newstr = ft_calloc(len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	return (newstr);
}
