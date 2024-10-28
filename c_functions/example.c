/*

ft_strlen (man 3 strlen)
ft_strcpy (man 3 strcpy)
ft_strcmp (man 3 strcmp)
ft_write (man 2 write)
ft_read (man 2 read)
ft_strdup (man 3 strdup)

*/

//FT_STRLEN

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//FT_STRCPY

char *strcpy(char *dest, const char *src)
{
	size_t i;
	
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
 }

//FT_STRCMP

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

//FT_WRITE

ssize_t write(int fd, const void *buf, size_t count);

//FT_READ

ssize_t read(int fd, void *buf, size_t count);


//FT_STRDUP

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



