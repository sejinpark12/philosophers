/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:24:07 by sejpark           #+#    #+#             */
/*   Updated: 2021/08/25 19:59:49 by sejpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/thread_manager.h"
#include "../includes/ft_atoi.h"

int	set_opt_data(int argc, char **argv, t_options *opts)
{
	if (argc < 5 || argc > 6)
		return (print_err("invalid parameters\n"));
	opts->num_philo = ft_atoi(argv[1]);
	if (opts->num_philo == 0)
		return (print_err("invalid parameters\n"));
	opts->time_die = ft_atoui(argv[2]) * 1000;
	if (opts->time_die == 0)
		return (print_err("invalid parameters\n"));
	opts->time_eat = ft_atoui(argv[3]) * 1000;
	if (opts->time_eat == 0)
		return (print_err("invalid parameters\n"));
	opts->time_sleep = ft_atoui(argv[4]) * 1000;
	if (opts->time_sleep == 0)
		return (print_err("invalid parameters\n"));
	opts->finish = 0;
	if (argc == 6)
	{
		opts->num_each_philo_eat = ft_atoi(argv[5]);
		if (opts->num_each_philo_eat == 0)
			return (print_err("invalid parameters\n"));
	}
	else
		opts->num_each_philo_eat = 0;
	return (0);
}

int	set_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = (t_philo *)malloc(sizeof(t_data) * data->opts.num_philo);
	if (data->philos == NULL)
		return (print_err("invalid parameters\n"));
	while (i < data->opts.num_philo)
	{
		data->philos[i].opts = &data->opts;
		data->philos[i].thds = &data->thds;
		data->philos[i].start_time = &data->start_time;
		data->philos[i].philo_idx = i + 1;
		data->philos[i].eating_cnt = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (set_opt_data(argc, argv, &data.opts))
		return (1);
	if (set_philos(&data))
		return (1);
	if (alloc_threads(&data))
		return (1);
	if (init_mutex(&data))
		return (1);
	if (create_threads(&data))
		return (1);
	finish_threads(&data.thds, data.opts.num_philo);
	return (0);
}
