/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:01:19 by atambo            #+#    #+#             */
/*   Updated: 2024/11/20 19:01:20 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	is_eating(t_phi *phi)
{
	if (!phi->data->run)
		return ;
	ft_mutex_lforks(phi);
	phi->death_t = ft_get_msec() + phi->data->ttd;
	phi->p_meals += 1;
	ft_mutex_printf(phi, "is  eating\n", 0);
	ft_msleep(phi->data->tte, phi);
	ft_mutex_uforks(phi);
	is_sleeping(phi);
}

void	is_sleeping(t_phi *phi)
{
	if (!phi->data->run)
		return ;
	ft_mutex_printf(phi, "is  sleeping\n", 0);
	ft_msleep(phi->data->tts, phi);
	is_thinking(phi);
}

void	is_thinking(t_phi *phi)
{
	if (!phi->data->run)
		return ;
	ft_mutex_printf(phi, "is  thinkig\n", 0);
	is_eating(phi);
}

void	*routine(void *args)
{	
	t_phi	*phi;

	phi = (t_phi *)args;
	if (phi->id % 2 == 0 && phi->data->phi_n > 2)
		usleep(1000);
	is_eating(phi);
	return (NULL);
}
