/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 14:44:49 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/03/04 15:10:50 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Convert string to double

static double	decimal_read(char *str)
{
	double	number;
	double	decimal;
	int		i;

	number = 0;
	decimal = 1;
	i = 0;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + str[i] - 48;
		decimal *= 10;
		i++;
	}
	number /= decimal;
	return (number);
}

double	ft_atod(char *str)
{
	double	number;
	int		i;
	int		negative;

	number = 0;
	i = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = negative * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.')
		number += decimal_read(str + i + 1);
	number *= negative;
	return (number);
}
