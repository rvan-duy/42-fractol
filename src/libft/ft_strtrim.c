/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ruben <rvan-duy@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 10:34:32 by ruben         #+#    #+#                 */
/*   Updated: 2021/03/04 14:40:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makenewstring(const char *str, char *newstr, int begin, int end)
{
	int	i;

	i = 0;
	while (i < (end - begin + 1))
	{
		newstr[i] = str[i + begin];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static int	ispartofset(const char *setter, char c)
{
	int	i;

	i = 0;
	while (setter[i] != '\0')
	{
		if (setter[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	findstart(const char *str, const char *setter)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ispartofset(setter, str[i]) != 1)
			return (i);
		i++;
	}
	return (i);
}

static int	findend(const char *str, const char *setter)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i != 0)
	{
		if (ispartofset(setter, str[i]) != 1)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		begin;
	int		end;
	char	*newstr;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	begin = findstart(s1, set);
	end = findend(s1, set);
	if (begin > end)
	{
		newstr = ft_calloc(sizeof(char), 1);
		if (!newstr)
			return (NULL);
		return (newstr);
	}
	newstr = ft_calloc(sizeof(char), (end - begin) + 2);
	if (!newstr)
		return (NULL);
	makenewstring(s1, newstr, begin, end);
	return (newstr);
}
