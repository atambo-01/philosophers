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

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdatomic.h>

// Forward declaration of t_phi
typedef struct s_phi t_phi;
typedef struct s_data t_data;

typedef struct s_data
{
    struct timeval  start;
    unsigned int    phi_n;
    unsigned int    ttd;
    unsigned int    tte;
    unsigned int    tts;
    unsigned int    e_min;
    pthread_mutex_t *mutex;
    t_phi           *phi;  // Now you can use t_phi
} t_data;

typedef struct s_phi
{
    pthread_t       thread;
    int             id;
    struct timeval  death_t;
    unsigned int    doa;
    t_data          *data;
    pthread_mutex_t *r_f;
    pthread_mutex_t *l_f;     
    t_phi           *next;
} t_phi;


// {
// 	dt -> death_time
// 	t -> thread
// }

// death_time = current_time + ttd;
// if (current_time >= death_time)
// 	dead = 1;


//init_philos.c
void	make_philos(t_phi **phi, t_data *data);
void	init_forks(t_phi *phi);
void	print_philos(t_phi *phi);

