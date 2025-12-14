/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <wipion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:33:07 by wipion            #+#    #+#             */
/*   Updated: 2025/12/14 22:27:30 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	end_printf_function(t_flag *root)
{
	t_flag	*tmp;

	while (root != NULL)
	{
		tmp = root->next;
		free(root);
		root = tmp;
	}
}

t_flag	*init_flag(int element, t_func_va_t f)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (flag == NULL)
		return (NULL);
	flag->element = element;
	flag->f = f;
	flag->next = NULL;
	return (flag);
}
int	add_flag(t_flag *root, int element, t_func_va_t f)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (flag == NULL)
		return (-1);
	while (root->next != NULL)
		root = root->next;
	root->next = flag;
	flag->next = NULL;
	flag->f = f;
	flag->element = element;
	return (0);
}
static int	start_printf_function(t_flag *root, char c, va_list infos)
{
	t_flag	*flag;
	int		len;

	len = 0;
	flag = root;
	while (flag != NULL)
	{
		if (flag->element == c)
		{
			len += flag->f(infos);
			return (len);
		}
		flag = flag->next;
	}
	return (len);
}
int get_command(char *str) 
{
    int     i;
    int     tmpresult;
    int     res;

    i = 0;
    res = 0;
    while (s[i] != '\0')
	{
		if (s[i] == root.element)
		{
			
			tmpresult = start_printf_function(root, s[i + 1], infos);
			if (tmpresult < 0)
				return (-1);
			res += tmpresult;
			i++;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			res++;
		}
		i++;
	}
}

void	*call_flag(void)
{
	t_flag	*root;

	root = init_flag("", &ft_printf_char);
	add_flag(root, "sa", &ft_printf_integer);
	add_flag(root, "sb", &ft_printf_integer);
	add_flag(root, "ss", &ft_printf_string);
	add_flag(root, "pa", &ft_printf_hexadecimallow);
	add_flag(root, "pb", &ft_printf_hexadecimalup);
	add_flag(root, "ra", &ft_printf_pointer);
	add_flag(root, "rb", &ft_printf_unsigned_int);
	add_flag(root, "rr", &ft_printf_percent);
    add_flag(root, "rra", &ft_printf_percent);
	add_flag(root, "rrb", &ft_printf_percent);
    add_flag(root, "rrr", &ft_printf_percent);
    return (root);
}
void    pushswap()
{
    create_node();
}
