/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipion <wipion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:30:33 by wipion            #+#    #+#             */
/*   Updated: 2025/12/14 22:03:02 by wipion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <stdarg.h>


typedef int	(*t_func_va_t)(va_list);
typedef struct s_flag
{
	char			*element;
	t_func_va_t		f;
	struct s_flag	*next;
}	t_flag;

#endif
