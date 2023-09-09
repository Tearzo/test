#include <stdlib.h>
#include <stdio.h>

/*int ft_atoz(char *str)
{
    int a = 0; int b = 0; int c = 1;

    while(((str[a] > 9 && str[a] < 13) && str[a] == 32) && str[a])
    a++;
    if (str[a] = 45)
    c = -c;
    a++;
    if (str[a] = 43)
    a++; 
    while((str[a] < '9' && str[a] > '0') && str[a])
    b = b * 10 + (str[a] - '0');
    a++;
    return (b * c);
}

int main()
{
    char fdp[] = "-+1561651651";
    printf("%d\n" ,atoi(fdp));
    printf("%d\n" ,ft_atoz(fdp));
}*/

//#include <stdio.h>

int ft_atoz(char *str)
{
    int a = 0;
    int b = 0;
    int c = 1;

    while ((str[a] == ' ' || (str[a] == '-' && str[a + 1] >= '0' && str[a + 1] <= '9') || (str[a] == '+' && str[a + 1] >= '0' && str[a + 1] <= '9')))
    {
        if (str[a] == '-')
            c = -c;
        a++;
    }

    while (str[a] >= '0' && str[a] <= '9')
    {
        b = b * 10 + (str[a] - '0');
        a++;
    }

    return (b * c);
}

int main()
{
    char fdp[] = "-+1561651651";
    printf("%d\n", atoi(fdp));
    printf("%d\n", ft_atoz(fdp));
    return 0;
}
