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

int		ft_putchar(char c);

int g_block_height;

int		calc_last_length(int size)
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

void	create_block(int size, int *block, int *g_block_height, int *tic)
{
	int door_size;
	int y;
	int x;
	int first;
	int half_empty;
	int center;

	center = 0;
	y = 0;
	if (size % 2 == 0)
		door_size = size - 1;
	else
		door_size = size;
	while (y < *g_block_height)
	{
		first = 0;
		x = 0;
		half_empty = (calc_last_length(size) - *tic) / 2 - 1;
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
			center = *tic / 2;
			if (*block == size - 1 == 1 && y >= *g_block_height - door_size)
			{
				if (center - door_size / 2 <= x && x <= center + door_size / 2)
				{
					if (door_size >= 5 && x == center + door_size / 2 - 1
						&& y == *g_block_height - door_size + door_size / 2)
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

void	define_tic(int *tick_counter, int *tick_add, int *tic)
{
	if (*tick_counter == 1)
	{
		*tic = *tic + *tick_add;
		*tick_add = *tick_add + 2;
		*tick_counter = 0;
	}
	else
	{
		*tic = *tic + *tick_add;
		*tick_counter = *tick_counter + 1;
	}
}

void	sastantua(int size)
{
	int i;
	int block;
	int tic;
	int tick_add;
	int tick_counter;

	i = 0;
	block = 0;
	g_block_height = 3;
	tic = 1;
	tick_add = 4;
	tick_counter = 0;
	while (i < size)
	{
		create_block(size, &block, &g_block_height, &tic);
		g_block_height++;
		i++;
		define_tic(&tick_counter, &tick_add, &tic);
	}
}
