/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 17:55:40 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/21 23:33:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	ft_strlcat(newstr, s2, len1 + len2 + 1);
	return (newstr);
}

char	*ft_strjoin_three(const char *s1, const char *s2, const char *s3)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	newstr = ft_calloc(len1 + len2 + len3 + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	ft_strlcat(newstr, s2, len1 + len2 + 1);
	ft_strlcat(newstr, s3, len1 + len2 + len3 + 1);
	return (newstr);
}
