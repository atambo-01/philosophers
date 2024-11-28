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

void	main_loop(t_phi *phi)
{
	t_phi	*first;

	first = NULL;
	while (phi != first)
	{
		if (pthread_create(&(phi->thread), NULL, routine, (phi)) != 0)
		{
			perror("Failed to create thread");
			return ;
		}
		if (!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
	first = NULL;
	while (phi != first)
	{
		pthread_join(phi->thread, NULL);
		if (!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
}

void	*is_eating(t_phi *phi)
{
	check_philos(phi);
	if (!phi->data->run)
		return (NULL);
	if (phi->l_f == NULL)
	{
		pthread_mutex_lock(phi->r_f);
		ft_mutex_printf(phi, "has taken a fork\n");
	}
	else if (phi->id % 2 == 0)
		ft_mutex_forks(phi, 1);
	else
		ft_mutex_forks(phi, 2);
	phi->death_t = ft_get_msec() + phi->data->ttd;
	if (phi->l_f != NULL)
		ft_mutex_printf(phi, "is eating\n");
	usleep(phi->data->tte * 1000);
	if (phi->l_f == NULL)
		pthread_mutex_unlock(phi->r_f);
	else
		ft_mutex_forks(phi, -1);
	check_philos(phi);
	is_thinking(phi);
}

void	*is_thinking(t_phi *phi)
{
	check_philos(phi);
	if (!phi->data->run)
		return (NULL);
	phi->p_meals += 1;
	ft_mutex_printf(phi, "is thinkig\n");
	check_philos(phi);
	is_sleeping(phi);
}

void	*is_sleeping(t_phi *phi)
{
	check_philos(phi);
	if (!phi->data->run)
		return (NULL);
	ft_mutex_printf(phi, "is sleeping\n");
	usleep(phi->data->tts);
	check_philos(phi);
	is_eating(phi);
}

void	*routine(void *args)
{	
	t_phi	*phi;

	phi = (t_phi *)args;
	is_eating(phi);
}
