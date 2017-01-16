/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 18:44:36 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/15 18:44:38 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);
int	calc_last_length(int size)
{
	int i;
	int result;
	int block_height;
	int diff_of_next;

	i = 0;
	result = 0;
	while (i < size)
	{
		block_height = i + 2;
		diff_of_next = 0;
		if (i % 2 == 0)
			diff_of_next = block_height * 3 + 2;
		else
			diff_of_next = block_height * 3 + 3;
		i++;
		result += diff_of_next;
	}
	result--;
	return (result);
}

void	create_block(int size, int btm_length, int *block, int *block_height, int *tic, int last_block)
{
	int door_size;
	int y;
	int x;
	int first;

	y = 0;

	if (size % 2 == 0)
		door_size = size - 1;
	else
		door_size = size;
	while (y < *block_height)
	{
		first = 0;
		x = 0;
		int half_empty = (btm_length - *tic) / 2 - 1;
		while (half_empty > 0)
		{
			ft_putchar(' ');
			half_empty--;
		}
		while (x < *tic)
		{
			if (first == 0)
			{
				ft_putchar('/');
				first++;
				continue;
			}
			int center = *tic / 2;
			if (last_block == 1 && y >= *block_height - door_size)
			{
				if (center - door_size / 2 <= x && x <= center + door_size / 2)
				{
					if (door_size >= 5 && x == center + door_size / 2 - 1
						&& y == *block_height - door_size + door_size / 2)
						ft_putchar('$');
					else
						ft_putchar('|');
				}
				else
					ft_putchar('*');
			}
			else
				ft_putchar('*');
			x++;
		}
		*tic = *tic + 2;
		ft_putchar('\\');
		ft_putchar('\n');
		y++;
	}
	*block = *block + 1;
}

void	sastantua(int size)
{
	int block;
	int block_height;
	int tic;
	int btm_length;
	int i;
	int tick_add;
	int tick_counter;
	int last_block;

	block = 0;
	block_height = 3;
	tic = 1;
	btm_length = calc_last_length(size);
	i = 0;
	tick_add = 4;
	tick_counter = 0;
	while (i < size)
	{
		last_block = 0;
		if (block == size - 1)
			last_block = 1;
		create_block(size, btm_length, &block, &block_height, &tic, last_block);
		block_height++;
		if (tick_counter == 1)
		{
			tic = tic + tick_add;
			tick_add += 2;
			tick_counter = 0;
		}
		else
		{
			tic = tic + tick_add;
			tick_counter++;
		}
		i++;
	}
}
