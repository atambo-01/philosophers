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

void	ft_msleep(long time, t_phi *phi)
{
	long start;

	start = ft_get_msec();
	time += start;
	while(1)
	{
		if ( ft_get_msec() >= time || phi->data->run == 0)
			return;
	}
}
