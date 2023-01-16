#include <stdio.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>

int mygetch()
{
    struct termios old_terminal_attr, new_terminal_attr;
    int symbol;

    tcgetattr(STDIN_FILENO, &old_terminal_attr);
    new_terminal_attr = old_terminal_attr;
    new_terminal_attr.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal_attr);
    symbol = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal_attr);

    return symbol;
}

int encrypt_cesar(int symbol, int shift)
{
    if (islower(symbol))
    {
        symbol = (symbol - 'a' + shift) % 26 + 'a';
    }
    else if (isupper(symbol))
    {
        symbol = (symbol - 'A' + shift) % 26 + 'A';
    }
    return symbol;
}

int main()
{
    const int shift = 1;
    int symbol;

    while ((symbol = mygetch()) != '\n')
    {
        symbol = encrypt_cesar(symbol, shift);
        printf("%c", symbol);
    }
    printf("\n");
    return 0;
}
