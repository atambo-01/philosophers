/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:51:47 by atambo            #+#    #+#             */
/*   Updated: 2024/11/16 14:51:48 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
#include "../libft/libft.h"
#include "../inc/philosophers.h"

void *function(void *args)
{
	t_phi *phi = (t_phi *)args; // Cast the argument to t_phi
	printf("---------------------------------------------------\n");
	printf("Hello from philosopher %d\n", phi->id);
//  printf("Start time: %ld.%06ld\n", phi->data->start.tv_sec, phi->data->start.tv_usec);
	return NULL;
}

int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		t_phi			*first;
		t_data			data;
		t_phi			*phi;

		data_init(av, &data);
		phi = NULL;
		make_philos(&phi, &data);
		print_philos(phi);
		first = phi;
		while(phi->next != first)
		{
			if (pthread_create(&(phi->thread), NULL, function, &(data.phi)) != 0)
			{
				perror("Failed to create thread");
				return 1;
			}
			phi = phi->next;
		}
		phi = phi->next;

		// while(data->doa == 0)
		// {
		// 	check_philo()
		// }

		while(phi->next != first)
		{
			pthread_join(phi->thread, NULL);
			phi = phi->next;
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s <number_of_threads>\n", av[0]);
		return 1;
	}
	return 0;
}

