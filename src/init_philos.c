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

void	data_init(char **av, t_data *data)
{
	if (av[1] && av[2] && av[3] && av[4])
	{
		data->run = 1;
		data->phi_n = ft_atoi(av[1]);
		data->ttd = ft_atoi(av[2]);
		data->tte = ft_atoi(av[3]);
		data->tts = ft_atoi(av[4]);
		if (data->phi_n <= 0 || data->ttd <= 0 || data->tte <= 0
			|| data->tts <= 0)
			data->run = 0;
	}
	else
		data->run = 0;
	if (av[5])
	{	
		data->e_min = ft_atoi(av[5]);
		if (data->phi_n <= 0)
			data->run = 0;
	}
	else
		data->e_min = -1;
	data->start = ft_get_msec();
}

static void	make_philos_02(t_phi **phi, t_data *data, int i)
{
	(*phi)->id = i;
	(*phi)->p_meals = 0;
	(*phi)->data = data;
	(*phi)->next = NULL;
}

void	make_philos(t_phi **phi, t_data *data)
{
	int		i;
	t_phi	*current;

	i = 1;
	(*phi) = ft_malloc(sizeof(t_phi));
	current = *phi;
	make_philos_02(phi, data, i);
	(*phi)->l_f = NULL;
	(*phi)->r_f = ft_malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*phi)->r_f, NULL);
	while (++i <= data->phi_n)
	{
		current->next = ft_malloc(sizeof(t_phi));
		current = current->next;
		make_philos_02(&current, data, i);
	}
	if (data->phi_n > 1)
	{	
		current->next = *phi;
		init_forks(*phi);
	}
	else
		init_death_t(*phi);
}

void	init_forks(t_phi *phi)
{
	t_phi	*prev;
	t_phi	*first;
	t_phi	*t_phi;

	t_phi = phi;
	first = t_phi;
	prev = t_phi;
	t_phi = t_phi->next;
	while (t_phi != first)
	{
		t_phi->l_f = prev->r_f;
		t_phi->r_f = ft_malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(t_phi->r_f, NULL);
		prev = t_phi;
		t_phi = t_phi->next;
	}
	if (t_phi != NULL)
		first->l_f = prev->r_f;
	init_death_t(phi);
}

void	init_death_t(t_phi *phi)
{
	t_phi	*first;
	long	time;

	time = phi->data->start + phi->data->ttd;
	first = NULL;
	while (phi != first)
	{
		phi->death_t = time;
		phi->p_meals = 0;
		if (!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
}
