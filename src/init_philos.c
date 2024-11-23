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

#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include "../inc/philosophers.h"

void	end_sim(void)
{
	exit(1);
}

void	data_init(char **av, t_data *data)
{
	if (av[1] && av[2] && av[3] && av[4])
	{
		data->phi_n = ft_atoi(av[1]);
		data->ttd = ft_atoi(av[2]);
		data->tte = ft_atoi(av[3]);
		data->tts = ft_atoi(av[4]);
		if (data->phi_n <= 0 || data->ttd <= 0 ||
				data->tte <= 0 || data->tts <= 0)
			end_sim();
	}
	else
		end_sim();
	if (av[5])
	{	
		data->e_min = ft_atoi(av[5]);
		if (data->phi_n <= 0)
			end_sim();
	}
	data->start = ft_get_msec();
}
void	make_philos(t_phi **phi, t_data *data)
{
	int i;

	i = 1;
	(*phi) = ft_malloc(sizeof(t_phi));
	(*phi)->id = i;
	(*phi)->doa = 1;
	(*phi)->data = data;
	(*phi)->next = NULL;
	(*phi)->l_f = NULL;
	(*phi)->r_f = ft_malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*phi)->r_f, NULL);
	t_phi *current = *phi;
	while (++i <= data->phi_n)
	{
		current->next = ft_malloc(sizeof(t_phi));
		current = current->next;
		current->id = i;
		current->doa = 1;
		current->data = data;
		current->next = NULL;
	}
	if(data->phi_n > 1)
	{	
		current->next = *phi;
		init_forks(*phi);
	}
}

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
	t_phi *first;

	first = NULL;
	while(phi != first)
	{
		phi->death_t = phi->data->start;
		phi->death_t += phi->data->ttd * 1000;
		if(!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
}
