/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ruben <rvan-duy@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 20:30:28 by ruben         #+#    #+#                 */
/*   Updated: 2020/11/15 21:12:04 by rubenz        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	newstr = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (str[i] != '\0')
	{
		newstr[i] = f(i, str[i]);
		i++;
	}
	return (newstr);
}
