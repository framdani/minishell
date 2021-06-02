/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:37:47 by framdani          #+#    #+#             */
/*   Updated: 2019/10/29 00:19:47 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				no_special_char(int c);
int				ft_atoi(const char*str);
int				ft_isalpha(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
size_t			ft_strlcat(char *dest, const char *src, size_t l);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
void			ft_bzero(void *s, size_t n);
int				ft_isascii(int c);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t l);
char			*ft_strrchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
int				ft_isdigit(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
int				ft_tolower(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strdup(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strjoin(char const *s1, const char *s2);
void			ft_lstadd_front(t_list **alst, t_list *n);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)
		(void *));
char			*ft_itoa(int n);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, const char *set);
int				get_next_line(int fd, char **line);
char			*ft_charjoin(char *str, char c);
#endif
