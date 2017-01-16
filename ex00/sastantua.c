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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
		{
			return ;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

int	calc_last_length(int size)
{
	int i;
	int result;
	i = 0;
	result = 0;
	while (i < size)
	{
		int block_height = i + 2;
		int diff_of_next = 0;
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

void	create_block(int size, int bottom_length, int *block, int *block_height, int *tic , int last_block)
{
	int door_size;
	if (size % 2 == 0)
		door_size = size - 1;
	else
		door_size = size;
	int y;
	int x;
	y = 0;
	int first;
	while (y < *block_height)
	{
		first = 0;
		x = 0;
		int half_empty = (bottom_length - *tic) / 2 - 1;
		while (half_empty > 0)
		{
			ft_putchar(' ');
			half_empty--;
		}
		while (x < *tic)
		{
			if (first == 0){
				ft_putchar('/');
				first++;
				continue;
			}
			int center = (*tic) / 2;
			if (last_block == 1 && y >= *block_height - door_size)
			{
				if (center - door_size / 2 <= x && x <= center + door_size / 2 ){
					if (door_size >= 5 && x == center + door_size / 2 -1 && y == *block_height - door_size + door_size / 2){
						ft_putchar('$');
					}else
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
	int block = 0;
	int block_height = 3;
	int tic = 1;

	int bottom_length = calc_last_length(size);

	int i = 0;
	int tick_add = 4;
	int tick_counter = 0;

	while (i < size)
	{
		int last_block = 0;
		if (block == size -1){
			last_block = 1;
		}
		create_block(size, bottom_length, &block, &block_height, &tic, last_block);
		block_height++;
		if (tick_counter == 1)
		{
			tic = tic + tick_add;
			tick_add += 2 ;
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
