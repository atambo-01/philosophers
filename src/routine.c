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

void	check_philos(t_phi *phi)
{
	t_phi	*first;
	int		count;

	count = 0;
	if (phi->data->run == 0)
		return ;
	if (ft_get_msec() >= phi->death_t)
	{
		phi->data->run = 0;
		ft_mutex_printf(phi, "has died\n", 1);
	}
	first = NULL;
	while (phi != first)
	{
		if (phi->data->e_min > -1 && phi->p_meals >= phi->data->e_min)
			count++;
		if (!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
	if (count == phi->data->phi_n)
		phi->data->run = 0;
}

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
	if (phi->id % 2 == 0)
		usleep(1000);
	is_eating(phi);
	return (NULL);
}
