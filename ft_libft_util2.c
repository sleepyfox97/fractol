#include "fractol.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

long	*ft_myatoi(char *s, long *num)
{
	long	minus;
	int		i;

	i = 0;
	minus = 1;
	*num = 0;
	if (!ft_isint(s))
		return (NULL);
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			minus = -1;
	while (s[i] != '\0')
		*num = (*num) * 10 + (s[i++] - '0');
	*num = (*num) * minus;
	if ((*num > INT_MAX || *num < INT_MIN))
		return (NULL);
	return (num);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	i = 0;
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	while (b1[i])
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (b1[i] - b2[i]);
}
