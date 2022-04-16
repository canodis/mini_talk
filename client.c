/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:00:29 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/16 13:50:22 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	*convert_binary(unsigned char c)
{
	int	i;
	int	*converted;

	converted = malloc(sizeof(int) * 8);
	i = 0;
	while (i < 8)
	{
		converted[i] = (c % 2);
		c /= 2;
		i++;
	}
	return (converted);
}

void	send_signal(int *binary, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (binary[i] == 0)
			kill(pid, SIGUSR1);
		else if (binary[i] == 1)
			kill(pid, SIGUSR2);
		usleep(210);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	*binary;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][++i])
		{
			binary = convert_binary((unsigned char)(argv[2][i]));
			send_signal(binary, pid);
			free(binary);
		}
	}
	else
		write(1, "Eksik veya fazla arguman !", 25);
}
