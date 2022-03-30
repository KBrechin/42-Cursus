/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:49:02 by kbrechin          #+#    #+#             */
/*   Updated: 2022/03/04 13:36:04 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s3;
	
	if (!(s1) && !(s2))
		return (0);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(s3 = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(s3, s1, s1_len + 1);
	ft_strlcat(s3 + (s1_len), s2, s2_len + 1);
	return (s3);
}
