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

int g_b_ht;

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

void	create_d(int is_py, int is_d, int is_knob)
{
	if (is_py)
	{
		if (is_d)
		{
			if (is_knob)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		else
			ft_putchar('*');
	}
	else
		ft_putchar('*');
}

void	create_block(int size, int *block, int *g_b_ht, int *t)
{
	int d;
	int y;
	int x;
	int first;
	int half_empty;

	y = 0;
	if (size % 2 == 0)
		d = size - 1;
	else
		d = size;
	while (y < *g_b_ht)
	{
		first = 0;
		x = 0;
		half_empty = (calc_last_length(size) - *t) / 2 - 1;
		while (half_empty-- > 0)
			ft_putchar(' ');
		while (x < *t)
		{
			if (first == 0)
			{
				ft_putchar('/');
				first++;
				continue;
			}
			create_d(*block == size - 1 == 1 && y >= *g_b_ht - d,
						(*t / 2) - d / 2 <= x && x <= (*t / 2) + d / 2,
						(d >= 5 && x == (*t / 2) + d / 2 - 1 && y == *g_b_ht - d + d / 2));
			x++;
		}
		*t = *t + 2;
		ft_putchar('\\');
		ft_putchar('\n');
		y++;
	}
	*block = *block + 1;
}

void	define_tic(int *tk_counter, int *tk_add, int *t)
{
	if (*tk_counter == 1)
	{
		*t = *t + *tk_add;
		*tk_add = *tk_add + 2;
		*tk_counter = 0;
	}
	else
	{
		*t = *t + *tk_add;
		*tk_counter = *tk_counter + 1;
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
	g_b_ht = 3;
	tic = 1;
	tick_add = 4;
	tick_counter = 0;
	while (i < size)
	{
		create_block(size, &block, &g_b_ht, &tic);
		g_b_ht++;
		i++;
		define_tic(&tick_counter, &tick_add, &tic);
	}
}
