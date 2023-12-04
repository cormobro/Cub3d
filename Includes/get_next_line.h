/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:13:22 by febonaer          #+#    #+#             */
/*   Updated: 2022/10/20 13:15:33 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_MAX 1024

char	*get_next_line(int fd);
char	*ft_strjoin(char *left_str, char *buff);
//size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*get_stack(char *stack);
char	*get_myline(char *stack);
char	*read_line(int fd, char *stack);

#endif
