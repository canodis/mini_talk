/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtosun <rtosun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:59:52 by rtosun            #+#    #+#             */
/*   Updated: 2022/04/16 13:53:38 by rtosun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	sig_handler(int signum)
{
	static int	i = 0;
	static int	harf = 0;

	if (signum == SIGUSR1)
		i++;
	else if (signum == SIGUSR2)
	{
		harf += ft_pow(2, i);
		i++;
	}
	if (i == 8)
	{
		ft_putchar_fd(harf, 1);
		harf = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
