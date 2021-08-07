/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 23:13:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/03/04 14:39:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Function converts an unsigned int to string

#include "libft.h"

static int	u_intlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_utoa(unsigned int n)
{
	char	*newstr;
	int		i;

	i = u_intlen(n);
	newstr = ft_calloc(sizeof(char), i + 1);
	if (!newstr)
		return (NULL);
	i--;
	if (n == 0)
		newstr[i] = '0';
	while (n > 0)
	{
		newstr[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (newstr);
}
