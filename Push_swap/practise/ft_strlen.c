
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

#include <string.h>

int main()
{
	char str[12] = "Hello World!";
	printf("ft = %lu\nreal = %lu\n", ft_strlen(str), strlen(str));
}
