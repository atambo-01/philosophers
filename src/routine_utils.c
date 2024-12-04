/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:27:11 by atambo            #+#    #+#             */
/*   Updated: 2024/11/27 15:27:12 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_mutex_printf(t_phi *phi, char *str, int i)
{
	long	time;

	if (phi->data->run == 0 && i == 0)
		return ;
	time = ft_get_msec() - phi->data->start;
	pthread_mutex_lock(&(phi->data->print));
	printf("%06ld %3d  %s", time, phi->id, str);
	pthread_mutex_unlock(&(phi->data->print));
}

void	ft_mutex_lforks(t_phi *phi)
{
	if (phi->id != phi->data->phi_n)
	{
		pthread_mutex_lock(phi->r_f);
		ft_mutex_printf(phi, "has taken a fork\n", 0);
		pthread_mutex_lock(phi->l_f);
		ft_mutex_printf(phi, "has taken a fork\n", 0);
	}
	else
	{
		pthread_mutex_lock(phi->l_f);
		ft_mutex_printf(phi, "has taken a fork\n", 0);
		pthread_mutex_lock(phi->r_f);
		ft_mutex_printf(phi, "has taken a fork\n", 0);
	}
}

void	ft_mutex_uforks(t_phi *phi)
{
	pthread_mutex_unlock(phi->l_f);
	pthread_mutex_unlock(phi->r_f);
}

void	single_phi(t_phi *phi)
{
	pthread_mutex_lock(phi->r_f);
	ft_mutex_printf(phi, "has taken a fork\n", 0);
	while (phi->data->run)
	{
		check_philos(phi);
	}
	pthread_mutex_unlock(phi->r_f);
}
