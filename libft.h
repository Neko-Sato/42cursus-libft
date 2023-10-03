/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:51:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 20:31:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <sys/types.h>

//	Mandatory Part 1
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);

//	Mandatory Part 2
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

//	Bonus part
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

//	extension
unsigned int		ft_abs(int n);
int					ft_average(int array[], size_t len);
void				ft_sort(int array[], size_t len);
int					ft_issorted(int array[], size_t len, int asc);
int					ft_max(int array[], size_t len);
int					ft_min(int array[], size_t len);
size_t				ft_digit(unsigned int n);
char				*ft_joinpath(char *base, char *path);
char				*ft_replace(const char *s, const char *before,
						const char *after);
void				*ft_memdup(void *src, size_t n);
char				*ft_strdup2(const char *s1);
char				*ft_strjoin2(char const *s1, char const *s2);
int					ft_isspace(int c);
char				*ft_utoa(unsigned int n);
int					ft_strcmp(const char *s1, const char *s2);
double				ft_atof(const char *str);
void				*ft_2darraynew(size_t size, size_t width, size_t height);
void				ft_2darraydel(void *array);

//		xlst
size_t				ft_xlstlen(void *lst, size_t size);
int					ft_xlstat(void *lst, size_t size, int index, void *dst);
int					ft_xlstappend(void *lst_ptr, size_t size, void *new);
int					ft_xlstinsert(void *lst_ptr, size_t size, void *new,
						int index);
int					ft_xlstpop(void *lst_ptr, size_t size, int index,
						void *dst);
void				ft_xlstclear(void *lst_ptr, size_t size);
void				*ft_xlst2array(void *lst, size_t size, size_t *__len);

//		strgen
# define STRGEN_BUFFSIZE 20

typedef struct s_strgen
{
	char			*str;
	char			buff[STRGEN_BUFFSIZE];
	size_t			position;
	int				error;
}					t_strgen;

t_strgen			*ft_strgennew(void);
void				ft_strgendel(t_strgen *strgen);
void				ft_strgenclearbuff(t_strgen *strgen);
void				ft_strgenchr(t_strgen *strgen, char insert);
void				ft_strgenstr(t_strgen *strgen, char *insert);
char				*ft_strgencomp(t_strgen *strgen);
char				*ft_strgenfetch(t_strgen *strgen, size_t len);

//		bufferio
typedef struct s_bufferio
{
	int				fd;
	t_strgen		*strgen;
}					t_bufferio;

t_bufferio			*ft_bufferionew(int fd, int close_on_error);
void				ft_bufferiodel(t_bufferio *io, int do_close);
int					ft_bufferioread(t_bufferio *io);
char				*ft_read(t_bufferio *io, int n);
char				*ft_readline(t_bufferio *io);
ssize_t				ft_write(t_bufferio *io, char *str);

#endif
