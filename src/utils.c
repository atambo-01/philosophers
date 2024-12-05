/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:30:18 by atambo            #+#    #+#             */
/*   Updated: 2024/11/22 14:30:19 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long	ft_get_msec(void)
{
	long			msec;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	msec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (msec);
}

void	ft_msleep(long time, t_phi *phi)
{
	long	start;

	start = ft_get_msec();
	time += start;
	while (1)
	{
		if (ft_get_msec() >= time || phi->data->run == 0)
			return ;
	}
}

static int	check_limits(const char *start, int sign)
{
	const char	*i_max;
	const char	*i_min;
	int			len;

	len = ft_strlen(start);
	i_max = "2147483647";
	i_min = "2147483648";
	if (len > 10)
	{
		return (0);
	}
	if (len == 10)
	{
		if ((sign > 0 && ft_strcmp(start, i_max) > 0)
			|| (sign < 0 && ft_strcmp(start, i_min) > 0))
		{
			return (0);
		}
	}
	return (1);
}

int	ft_pre_atoi(char *str)
{
	int		sign;
	char	*start;

	sign = 1;
	if (str == NULL)
		return (0);
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	start = str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (check_limits(start, sign));
}
