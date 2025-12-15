#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}


int     **swap_a(int **tab)
{
	int	result;
	int *b;
	int	i;

    if (!tab[0] || ft_strlen(tab[0]) == 1)
		return (tab);
	result = ft_strlen(tab[0]) - 2;
	if (!tab[1])
	{
		tab[1] = malloc(sizeof(int) * result);
		if (!b)
			return (b);
	}
	i = 0;
	while (result <= ft_strlen(tab[0]))
	{
		tab[1][i] = tab[0][result];
		i++;
		result++;
	}
	return (tab);
}

int     **swap_b(int **tab)
{
	int	result;
	int *b;
	int	i;

    if (!tab[1] || ft_strlen(tab[1]) == 1)
		return (tab);
	result = ft_strlen(tab[0]) - 2;
	i = 0;
	while (result <= ft_strlen(tab[1]))
	{
		tab[0][i] = tab[1][result];
		i++;
		result++;
	}
	return (tab);
}

int		**push_a(int **tab)
{
	int	i;
	int tmp;
	int totala;
	int	totalb;

	i = 0;
	if (!tab[0])
		return (tab);
	totala = ft_strlen(tab[0]);
	totalb = ft_strlen(tab[1]);
	tmp = tab[0][totala];
	tab[0][totala] = tab[1][totalb];
	tab[1][totalb] = tmp;
	return (tab);
}


int		**push_b(int **tab)
{
	int	i;
	int tmp;
	int totala;
	int	totalb;

	i = 0;
	if (!tab[0])
		return (tab);
	totala = ft_strlen(tab[0]);
	totalb = ft_strlen(tab[1]);
	tmp = tab[1][totalb];
	tab[1][totalb] = tab[0][totala];
	tab[0][totala] = tmp;
	return (tab);
}

int		**reverse_a(int **tab)
{
	int	i;
	int	j;
	int size;
	int	temp;

	if (!tab[0])
		return (tab);
	size = ft_strlen(tab[0]);
	i = size - 1;
	temp = 0;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			temp = tab[0][i];
			tab[0][i] = tab[0][j];
			tab[0][j] = temp;
			j--;
		}
		i--;
	}
	return (tab);
}

int		**reverse_b(int **tab)
{
	int	i;
	int	j;
	int size;
	int	temp;

	if (!tab[1])
		return (tab);
	size = ft_strlen(tab[1]);
	i = size - 1;
	temp = 0;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			temp = tab[1][i];
			tab[1][i] = tab[1][j];
			tab[1][j] = temp;
			j--;
		}
		i--;
	}
	return (tab);
}
