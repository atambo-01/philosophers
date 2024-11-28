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

#include "../inc/philosophers.h"

int	main(int ac, char **av)
{
	t_phi			*first;
	t_phi			*phi;
	t_data			data;

	if (ac == 5 || ac == 6)
	{
		data_init(av, &data);
		phi = NULL;
		make_philos(&phi, &data);
		first = NULL;
		// print_data(&data);
		// print_philos(phi);
		main_loop(phi);
		free_phi(&phi);
	}
	return (0);
}
