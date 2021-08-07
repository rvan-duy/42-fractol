/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ruben <rvan-duy@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 15:51:14 by ruben         #+#    #+#                 */
/*   Updated: 2021/02/12 14:11:47 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*newstr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = intlen(n);
	newstr = ft_calloc(sizeof(char), i + 1);
	if (!newstr)
		return (NULL);
	i--;
	if (n == 0)
		newstr[i] = '0';
	if (n < 0)
	{
		newstr[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		newstr[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (newstr);
}
