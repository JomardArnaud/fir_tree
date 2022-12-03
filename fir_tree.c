void    my_putchar(char c);

void    printStr(char *str) 
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        my_putchar(str[i]);
    }
}

int     main() 
{
    printStr("Hello world !\n");
    return 0;
}