/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 15:12:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/03/04 14:41:02 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (count);
}

static int	findstart(const char *s, char c, int i)
{
	while (s[i])
	{
		if (s[i] != c)
			return (i);
		i++;
	}
	return (i);
}

static int	findlen(const char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] != c && s[start] != '\0')
	{
		i++;
		start++;
	}
	return (i);
}

static char	**splitstr(const char *s, char c, int arraylen, char **finalstr)
{
	int	start;
	int	len;
	int	i;

	i = 0;
	start = 0;
	len = 0;
	while (i < arraylen)
	{
		start = findstart(s, c, start + len);
		len = findlen(s, c, start);
		finalstr[i] = ft_substr(s, start, len);
		if (!finalstr[i])
		{
			while (i > 0)
			{
				i--;
				free(finalstr[i]);
			}
			free(finalstr);
			return (NULL);
		}
		i++;
	}
	return (finalstr);
}

char	**ft_split(char const *s, char c)
{
	char	**finalstr;
	int		arraylen;

	if (!s)
		return (NULL);
	arraylen = countwords(s, c);
	finalstr = ft_calloc(arraylen + 1, sizeof(char *));
	if (!finalstr)
		return (NULL);
	finalstr = splitstr(s, c, arraylen, finalstr);
	if (!finalstr)
		return (NULL);
	return (finalstr);
}
