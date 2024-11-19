#include <stdio.h>
#include <stdbool.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;

	str = s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((unsigned char *)str);
		str++;
	}
	return (0);
}

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

int	ft_power(int x, unsigned int y)
{
	int	temp;

	if (y == 0)
		return (1);
	temp = ft_power(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}

bool	nb_is_correct(const char *nb, const char *base, int base_len)
{
	while (*nb)
	{
		if (!ft_memchr(base, *nb, base_len))
			return (false);
		nb++;
	}
	return (true);
}

bool	base_is_correct(const char *base)
{
	static bool chars[256];
	while (*(base))
	{
		//if (!ft_isalnum(*base))
			//return (false);
		//if (*(base + 1))
		//	if (ft_memchr(base + 1, *base, base_len))
		//		return (false);
		if (chars[(int)*base] == true)
			return false;
		chars[(int)*base] = true;
		base++;
	}
	return (true);
}

bool	parsing(const char *nb, const char *base, int *base_len)
{
	if (!base || !nb)
		return (false);
	*base_len = ft_strlen(base);
	if (*base_len <= 1)
		return (false);
	if (!base_is_correct(base))
		return (false);
	if (!nb_is_correct(nb, base, *base_len))
		return (false);
	return (true);
}

int	get_index(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			break ;
		i++;
	}
	return (i);
}

int	ft_atoi_base(const char *nptr, const char *base)
{
	int		nb;
	int		base_len;
	size_t	nb_len;

	base_len = 0;
	if (!parsing(nptr, base, &base_len))
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	nb = 0;
	nb_len = ft_strlen(nptr);
	while (*nptr)
	{
		nb += get_index(*nptr, base) * ft_power(base_len, nb_len - 1);
		nptr++;
		nb_len--;
	}
	return (nb);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi_base(argv[1], argv[2]));
}
