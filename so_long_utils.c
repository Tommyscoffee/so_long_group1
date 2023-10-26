#include "so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		ans;

	ans = 0;
	while (*s1 != 0 || *s2 != 0)
	{
		ans = (unsigned char)*(s1) - (unsigned char)*(s2);
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (ans);
		s1 += 1;
		s2 += 1;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (1)
	{
		if (*s == (char)c)
			p = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (p);
}
