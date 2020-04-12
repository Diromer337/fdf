/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:36:34 by eberta            #+#    #+#             */
/*   Updated: 2019/09/06 21:34:04 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include "string.h"
# include "stdlib.h"
# include "unistd.h"
# include "sys/types.h"
# include "sys/stat.h"
# include "fcntl.h"
# define BUFF_SIZE 32
# define FDMAX 10240

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_strlist
{
	char				*data;
	struct s_strlist	*next;
}						t_strlist;

int						ft_atoi(const char *str);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
size_t					ft_strlen(const char *str);
void					ft_putnbr(int n);
char					*ft_strdup(const char *src);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *str1, const char *str2,
							size_t num);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t len);
char					*ft_strcat(char *destptr, const char *srcptr);
char					*ft_strncat(char *destptr, char *srcptr, size_t num);
char					*ft_strchr(const char *string, int symbol);
char					*ft_strrchr(const char *string, int symbol);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strsub(char const *s, unsigned int start,
							size_t len);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
void					*ft_memset(void *memptr, int val, size_t num);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
void					ft_putendl(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src,
							int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_isupper(int c);
int						ft_islower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstaddtail(t_list **alst, t_list *new);
int						ft_charind(const char *str, int c);
int						ft_str_is_printable(char *s);
void					ft_str_replace(char *str, char to_replace,
							char replace);
int						get_next_line(const int fd, char **line);
int						word_num(char const *s, char c);
int						ft_atoi_base(const char *str, int base);
int						ft_isspace(int c);
int						ft_isnumber_base(char *str, int base);
#endif
