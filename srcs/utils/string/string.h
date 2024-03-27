#ifndef STRING_H
# define STRING_H

#include <stdlib.h>

int ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substring(char const *s, unsigned int start, size_t end);


#endif
