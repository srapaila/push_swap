/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <srapaila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:05:38 by srapaila          #+#    #+#             */
/*   Updated: 2025/04/17 16:59:23 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <ctype.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif
