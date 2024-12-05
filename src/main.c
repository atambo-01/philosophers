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
	t_phi	*phi;
	t_data	data;
	int		i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while(i < ac)
		{
			if (ft_pre_atoi(av[i]) == 0)
			{
				(ft_error("Error.\nBad formating, use decimal numbers.", 1));
				return(ft_error("Decimals that fit in an int.", 1));
			}
			i++;
		}
		data_init(av, &data);
		phi = NULL;
		make_philos(&phi, &data);
		main_loop(phi);
		free_phi(&phi);
		return(0);
	}
	else
	{
		return(ft_error("Error.\nInsuficient params need 5 or 6.", 1));
	}
}
