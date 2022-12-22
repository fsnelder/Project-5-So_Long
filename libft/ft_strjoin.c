#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int	strln(char const *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	j;
	unsigned int	k;
	char			*s3;

	if (!s2)
		return (0);
	s3 = malloc(strln(s1) + strln(s2) + 1);
	if (s3 == 0)
		return (0);
	j = 0;
	k = 0;
	while (s1[j] != '\0')
	{
		s3[j] = s1[j];
		j++;
	}
	while (s2[k] != '\0')
	{
		s3[j + k] = s2[k];
		k++;
	}
	s3[j + k] = '\0';
	return (s3);
}

static int	strln(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i + 1);
}
