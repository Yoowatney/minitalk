/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:45:34 by yoyoo             #+#    #+#             */
/*   Updated: 2021/05/17 22:35:43 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *ptr, size_t size);
void				*ft_calloc(size_t nmemb, size_t size);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void				*ft_memcpy(void *dest, const void *source, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memset(void *ptr, int value, size_t num);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
char				**ft_split(char const *str, char c);

char				*ft_strchr(char *str, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, char const *src, unsigned long size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *ptr1, const char *ptr2, size_t num);
char				*ft_strnstr(const char *str, const char *find, size_t len);
char				*ft_strrchr(char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_toupper(int c);
int					ft_tolower(int c);
t_list				*ft_lstnew(void	*cont);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst
		, void *(*f)(void *), void (*del)(void *));

int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);

#endif
