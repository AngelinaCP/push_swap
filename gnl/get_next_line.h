#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	*next_line(char **start_l, char **line);

#endif
