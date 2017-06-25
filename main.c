#include <stdio.h>

void	sastantua(int size);

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') || (str[i] == ' ') || (str[i] == '\f') ||
		   (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int) str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return 0;
	int size = ft_atoi(argv[1]);
	if (size <= 0)
		return (0);
	sastantua(size);
}