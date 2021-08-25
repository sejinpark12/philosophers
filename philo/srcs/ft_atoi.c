/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:49:49 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/25 20:01:16 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_atoi.h"

int	ft_isspace(const char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		tmp_i;
	long	result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	tmp_i = i;
	while (str[tmp_i])
		if (!ft_isdigit(str[tmp_i++]))
			return (0);
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (result > 2147483647 && result < 9223372036854775807L)
		return (0);
	return (result);
}

unsigned int	ft_atoui(const char *str)
{
	int		i;
	int		tmp_i;
	long	result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	tmp_i = i;
	while (str[tmp_i])
		if (!ft_isdigit(str[tmp_i++]))
			return (0);
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (result > 4294967295 && result < 9223372036854775807L)
		return (0);
	return (result);
}
