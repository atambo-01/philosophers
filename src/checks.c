/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:16:20 by atambo            #+#    #+#             */
/*   Updated: 2024/12/11 19:16:23 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	check_meals(t_phi *phi)
{
	t_phi	*first;
	int		count;

	count = 0;
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

void	check_philos(t_phi *phi)
{
	if (phi->data->run == 0)
		return ;
	if (ft_get_msec() >= phi->death_t)
	{
		if (phi->data->run == 0)
			return ;
		phi->data->run = 0;
		ft_mutex_printf(phi, "has died\n", 1);
	}
	check_meals(phi);
}
