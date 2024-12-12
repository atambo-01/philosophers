/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:19:51 by atambo            #+#    #+#             */
/*   Updated: 2024/11/30 00:19:53 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	create_threads(t_phi *phi)
{
	t_phi	*first;

	first = NULL;
	while (phi != first)
	{
		if (pthread_create(&(phi->thread), NULL, routine, phi) != 0)
		{
			perror("Failed to create thread");
			return ;
		}
		if (!first)
			first = phi;
		if (phi->next)
			phi = phi->next;
	}
}

static void	join_threads(t_phi *phi)
{
	t_phi	*first;

	first = NULL;
	while (phi != first)
	{
		pthread_join(phi->thread, NULL);
		if (!first)
			first = phi;
		phi = phi->next;
	}
}

void	main_loop(t_phi *phi)
{
	if (phi->l_f == NULL)
	{
		single_phi(phi);
		return ;
	}
	create_threads(phi);
	while (phi->data->run == 1)
	{
		check_philos(phi);
		phi = phi->next;
		usleep(2000);
	}
	join_threads(phi);
}

static void	free_forks(t_phi **phi)
{
	t_phi	*current;
	t_phi	*first;

	if (!phi || !*phi)
		return ;
	current = *phi;
	first = *phi;
	while (current)
	{
		current->l_f = NULL;
		ft_free((void **)&(current->r_f));
		if (current->next == first)
			break ;
		current = current->next;
	}
}

void	free_phi(t_phi **phi)
{
	t_phi	*current;
	t_phi	*next;
	t_phi	*first;

	if (!phi || !*phi)
		return ;
	free_forks(phi);
	current = *phi;
	first = *phi;
	while (current)
	{
		next = current->next;
		ft_free((void **)&current);
		if (next == first)
			break ;
		current = next;
	}
	*phi = NULL;
}
