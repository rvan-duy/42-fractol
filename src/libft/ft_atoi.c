/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ruben <rvan-duy@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:57:28 by ruben         #+#    #+#                 */
/*   Updated: 2021/02/12 14:08:10 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *nptr)
{
	int	number;
	int	i;
	int	negative;

	number = 0;
	i = 0;
	negative = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		negative = negative * -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
	{
		number = number * 10 + nptr[i] - 48;
		i++;
	}
	return (negative * number);
}
