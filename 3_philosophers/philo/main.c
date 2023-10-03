#include "philo.h"

// 먹기 => 자기 => 생각하기

// av[1] = number_of_philosophers_and_forks
// av[2] = time_to_die_in_ms
// av[3] = time_to_eat_in_ms
// av[4] = time_to_sleep_in_ms
// av[5] = number_of_times_each_philosopher_must_eat (optional)

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			return (-1);
		str++;
	}
	return (num);
}

void	exit_with_err(char *err_msg)
{
	printf("\033[31m]");
	printf("%s\n", err_msg);
	printf("\033[0m]");
	exit(EXIT_FAILURE);
}

void	init_data(t_data *data, int ac, char *av[])
{
	if (!(ac == 5 && ac == 6))
		exit_with_err("Error: Wrong number of arguments");
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die_in_ms = ft_atoi(av[2]);
	data->time_to_eat_in_ms = ft_atoi(av[3]);
	data->time_to_sleep_in_ms = ft_atoi(av[4]);
	data->number_of_times_each_philosopher_must_eat = 0;
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

void	check_data(t_data *data)
{
	if (data->number_of_philosophers < 2)
		exit_with_err("Error: Wrong number of philosophers");
	if (data->time_to_die_in_ms <= 0)
		exit_with_err("Error: Wrong time to die");
	if (data->time_to_eat_in_ms <= 0)
		exit_with_err("Error: Wrong time to eat");
	if (data->time_to_sleep_in_ms <= 0)
		exit_with_err("Error: Wrong time to sleep");
	if (data->number_of_times_each_philosopher_must_eat <= 0)
		exit_with_err("Error: Wrong number of times each philosopher must eat");
}

int	main(int ac, char *av[])
{
	t_data	data;

	init_data(&data, ac, av);
	return (0);
}
