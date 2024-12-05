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
	pthread_mutex_t	print;
	atomic_long		start;
	atomic_int		phi_n;
	atomic_int		meals;
	atomic_int		ttd;
	atomic_int		tte;
	atomic_int		tts;
	atomic_int		e_min;
}	t_data;

typedef struct s_phi
{
	atomic_int		id;
	atomic_int		p_meals;
	t_data			*data;
	t_phi			*next;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*l_f;
	atomic_long		death_t;
	atomic_long		last_meal;
	pthread_t		thread;
}	t_phi;

//inits.c
void	data_init(char **av, t_data *data);
// static void	make_philos_02(t_phi **phi, t_data *data, int i);
void	make_philos(t_phi **phi, t_data *data);
void	init_forks(t_phi *phi);
void	init_death_t(t_phi *phi);

//libft.c
int		ft_atoi(const char *nptr);
void	ft_free(void **ptr);
void	*ft_malloc(size_t size);
int		ft_error(char *msg, int e);

//str.c
int		ft_strlen(char const *str);
int		ft_strcmp(const char *s1, const char *s2);

//routine_utils.c
void	ft_mutex_printf(t_phi *phi, char *str, int i);
void	ft_mutex_lforks(t_phi *phi);
void	ft_mutex_uforks(t_phi *phi);
void	single_phi(t_phi *phi);

//routine.c
void	check_philos(t_phi *phi);
void	is_eating(t_phi *phi);
void	is_sleeping(t_phi *phi);
void	is_thinking(t_phi *phi);
void	*routine(void *args);

//threads.c
// void	create_threads(t_phi *phi);
// void	join_threads(t_phi *phi);
void	main_loop(t_phi *phi);
//static void	free_forks(t_phi **phi);
void	free_phi(t_phi **phi);

//utils.c
long	ft_get_msec(void);
void	ft_msleep(long time, t_phi *phi);
int		ft_pre_atoi(char *str);

//extra.c
void	print_data(t_data *data);
void	print_philos(t_phi *phi);

#endif
