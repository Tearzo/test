#include <stdio.h>
#include <stdlib.h>

int	ft_ischarset(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, int i, char *charset)
{
	int	count;

	count = 0;
	while (str[i] != '\0' && !ft_ischarset(str[i], charset))
	{
		count++;
		i++;
	}
	return (count + 1);
}

char	*ft_strdup(char *dest, char *str, int i, char *charset)
{
	int	k;
	int	len;

	k = 0;
	len = ft_strlen(str, i, charset);
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	while (str[i] != '\0' && !ft_ischarset(str[i], charset))
	{
		dest[k] = str[i];
		k++;
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

int	ft_countwords(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (ft_ischarset(str[i], charset) && str[i] != '\0')
			i++;
		if (!ft_ischarset(str[i], charset) && str[i] != '\0')
		{
			count++;
			i++;
		}
		while (!ft_ischarset(str[i], charset) && str[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**dest;
	int		k;

	i = 0;
	k = 0;
	dest = malloc(sizeof(char *) * (ft_countwords(str, charset) + 1));
	if (!dest)
		return (NULL);
	while (str[i] != '\0')
	{
		while (ft_ischarset(str[i], charset) && str[i] != '\0')
			i++;
		if (!ft_ischarset(str[i], charset) && str[i] != '\0')
		{
			dest[k] = ft_strdup(dest[k], str, i, charset);
			i++;
			k++;
		}
		while (!ft_ischarset(str[i], charset) && str[i] != '\0')
			i++;
	}
	dest[k] = NULL;
	return (dest);
}

int	main(void)
{
 	char	*str;
 	char	*charset;

 	str = "4 4";
 	charset = ", ";
 	ft_split(str, charset);
 	return (0);
}