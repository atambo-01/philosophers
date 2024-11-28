/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atambo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:55:37 by atambo            #+#    #+#             */
/*   Updated: 2024/11/16 15:55:39 by atambo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdatomic.h>

// Forward declaration of t_phi
typedef struct s_phi	t_phi;
typedef struct s_data	t_data;

typedef struct s_data
{
	atomic_int		run;
	atomic_long		start;
	unsigned int	phi_n;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	int	e_min;
}	t_data;

typedef struct s_phi
{
	int				id;
	int				p_meals;
	t_data			*data;
	t_phi			*next;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*l_f;
	long			death_t;
	pthread_t		thread;
}	t_phi;

//init_philos.c
void	data_init(char **av, t_data *data);
void	make_philos(t_phi **phi, t_data *data);
void	init_forks(t_phi *phi);
void	init_death_t(t_phi *phi);

//utils.c
void	print_data(t_data *data);
void	print_philos(t_phi *phi);
long    ft_get_msec(void);
void	free_phi(t_phi **phi);

//routine_utils.c
void 	check_philos(t_phi *phi);
void    ft_mutex_printf(t_phi *phi, char *str);
void	ft_mutex_forks(t_phi *phi, int i);
void	set_death_t(t_phi *phi);

//routine.c
void    *is_eating(t_phi *phi);
void    *is_thinking(t_phi *phi);
void    *is_sleeping(t_phi *phi);
void    *routine(void *args);

#endif
