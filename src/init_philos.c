/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:41:27 by atambo            #+#    #+#             */
/*   Updated: 2024/11/20 15:41:28 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	init_forks(t_phi *phi)
{
	t_phi *prev;
	t_phi *first;

	first = phi;
	prev = phi;
	phi = phi->next;
	while(phi != first)
	{
		phi->l_f = prev->r_f;
		phi->r_f = ft_malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(phi->r_f, NULL);
		prev = phi;
		phi = phi->next;
	}
	if ( phi != NULL)
		first->l_f = prev->r_f;
	init_death_t(phi);
}
void    init_death_t(t_phi *phi)
{
	t_phi	*first;
	long	time;

	time = phi->data->start + phi->data->ttd;
	first = NULL;
	while(phi != first)
	{
			printf("\n%ld\n", time);
		phi->death_t = time;
		phi->p_meals = 0; 
		if(!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
}
