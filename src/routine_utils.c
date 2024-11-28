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

void	check_philos(t_phi *phi)
{
	long	curr;
	t_phi	*first;
	unsigned int count;

	curr = ft_get_msec();
	if (curr >= phi->death_t)
	{
		ft_mutex_printf(phi, "has died\n");
		phi->data->run = 0;
	}
	first = NULL;
	while (phi != first)
	{
		if (phi->data->e_min > 0 && phi->p_meals >= phi->data->e_min)
			count++;
		if(!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
	if (count == phi->data->phi_n)
		phi->data->run = 0;
}

void	ft_mutex_printf(t_phi *phi, char *str)
{
	long			time;
	pthread_mutex_t	print;

	if (!phi->data->run)
		return ;
	time = ft_get_msec() - phi->data->start;
	pthread_mutex_init(&print, NULL);
	pthread_mutex_lock(&print);
	printf("%06ld\t%d %s", time, phi->id, str);
	pthread_mutex_unlock(&print);
}

void	ft_mutex_forks(t_phi *phi, int i)
{
	if (i == 1)
	{
		pthread_mutex_lock(phi->l_f);
		ft_mutex_printf(phi, "has taken a fork\n");
		pthread_mutex_lock(phi->r_f);
		ft_mutex_printf(phi, "has taken a fork\n");
	}
	else if (i == 2)
	{
		pthread_mutex_lock(phi->r_f);
		ft_mutex_printf(phi, "has taken a fork\n");
		pthread_mutex_lock(phi->l_f);
		ft_mutex_printf(phi, "has taken a fork\n");
	}
	else if (i == -1)
	{
		pthread_mutex_unlock(phi->l_f);
		pthread_mutex_unlock(phi->r_f);
	}
}
