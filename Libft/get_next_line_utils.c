/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:57:18 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 15:14:20 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//size_t	ft_strlen(const char *s)
//{
//	size_t i;

//	i = 0;
//	while (s[i] != '\0')
//		i++;
//	return (i);
//}

char	*ft_strdup_gnl(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	if (dst == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup_gnl(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup_gnl(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy_gnl(newstr, s1, s1_len + 1);
	free(s1);
	ft_strlcat_gnl(newstr, s2, s1_len + s2_len + 1);
	return (newstr);
}
