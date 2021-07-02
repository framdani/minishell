/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:38:40 by akhalidy          #+#    #+#             */
/*   Updated: 2021/07/02 17:26:39 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1000
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_list
{
	char			*env;
	char			*value;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlst
{
	int				id;
	void			*content;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}					t_dlst;

typedef struct		s_mem
{
	void			*mem;
	struct s_mem	*next;
}					t_mem;

char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(char *var, char *value);
void				ft_lstadd_back(t_list **alst, t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
float				ft_atof(char **s, int i, float x, float signe);
int					get_next_line(int fd, char **line);
t_dlst				*ft_dlstnew(void *content, int id);
void				ft_dlstadd_back(t_dlst **alst, t_dlst *lst);
t_dlst				*ft_dlstlast(t_dlst *lst);
char				**ft_free(char **ptr);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_dlstclear(t_dlst **lst, void (*del)(void *));
void				ft_dlstdelone(t_dlst *lst, void (*del)(void*));
int					ft_split_num(char **s);
int					ft_isnumber(char *s, int *signe);
int					ft_char_frequency(char c, char *s);
int					ft_is_integer(char *s, int *signe);
t_list  			*ft_prev_node(t_list *lst, char *content);
void				ft_delete_node(t_list **lst, char *env);
void				ft_bubblesort(char *arr[], int n);
void				ft_lstbubblesort(t_list	*lst);
void				ft_swap_str(char **str1, char **str2);
t_list				*ft_find_node(t_list *lst, char *content);

//maybe to delet
void				ft_print_list(t_list *lst);
void				ft_putstrstr_fd(char **str, int fd);
//Helpers
t_list				*ft_arr_to_list(char **str);
char				**ft_list_to_arr(t_list *lst);
int 				ft_is_flag(char *str, char c);
int 				ft_strstrlen(char **str);
void				ft_strtolower(char **str);

char				*ft_charjoin(char *str, char c);
int					no_special_char(int c);
#endif
