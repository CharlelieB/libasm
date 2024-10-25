

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}



char	*ft_strdup(const char *s)
{
	size_t		n;
	char		*cp;

	n = ft_strlen(s) + 1;
	cp = malloc(n * sizeof(char));
	if (cp == 0)
		return (0);
	ft_strlcpy(cp, s, n);
	return (cp);
}



