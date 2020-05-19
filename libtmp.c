void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int nb = 0;
    
    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb = nb + 1;
    }
}

int my_strlen(char *str)
{
    int nb;

    nb = 0;
    while (str[nb] != '\0')
        nb++;
    return (nb);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    i = 0;
    while (s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

int my_putnbr(int nb)
{
    int i;

    if (nb < 0 && nb != -2147483648) {
        write(1, "-", 1);
        i = -nb;
        my_putnbr(i);
    }
    else if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else {
        i = nb;
        if (i >= 10)
            my_putnbr(i / 10);
        my_putchar(i % 10 + '0');
    }
    return (0);
}

void my_putnbr_base(int nb, int size)
{
    if (nb >= size)
        my_putnbr_base(nb / size, size);
    my_putnbr(nb % size);
}

