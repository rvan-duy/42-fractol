/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ruben <rvan-duy@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 15:40:12 by ruben         #+#    #+#                 */
/*   Updated: 2020/11/07 14:14:27 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	while (str[i] != c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&str[i]);
}
