/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:18:39 by atambo            #+#    #+#             */
/*   Updated: 2024/11/28 11:18:45 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_data(t_data *data)
{
	printf("Data\n");
	printf("---------------------------------------------------\n");
	printf("run\t%d\n", data->run);
	printf("start\t%ld\n", data->start);
	printf("phi_n\t%d\n", data->phi_n);
	printf("ttd\t%d ms\n", data->ttd);
	printf("tte\t%d ms\n", data->tte);
	printf("tts\t%d ms\n", data->tts);
	printf("e_min\t%d\n", data->e_min);
	printf("---------------------------------------------------\n");
}

void	print_philos(t_phi *phi)
{
	t_phi	*first;

	first = NULL;
	printf("---------------------------------------------------\n");
	printf("Philos\n");
	while (phi != first)
	{
		printf("---------------------------------------------------\n");
		printf("thread\t%ld\n", phi->thread);
		printf("id\t%d\n", phi->id);
		printf("death_t\t%ld\n", phi->death_t);
		printf("meals\t%d\n", phi->p_meals);
		printf("data\t%p\n", phi->data);
		printf("l_f\t%p\n", phi->l_f);
		printf("r_f\t%p\n", phi->r_f);
		if (!first)
			first = phi;
		if (phi->next)
		{		
			printf("next\t%d\n", phi->next->id);
			phi = phi->next;
		}
	}
	printf("---------------------------------------------------\n");
}
