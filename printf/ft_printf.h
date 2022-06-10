/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:01:54 by kbrechin          #+#    #+#             */
/*   Updated: 2022/06/10 19:10:14 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void			flag_handeler(char c, va_list *args, int *counter);
int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_strlen(char *c);
int				ft_putstr(char *c);
unsigned int	ft_intlen(unsigned int n);
void			ft_putnbr(int n, int *counter);
void			ft_uputnbr(unsigned int n, int *counter);
void			ft_itoh(size_t n, int *counter, char c);
void			ft_ptr(void *p, int *counter);

#endif