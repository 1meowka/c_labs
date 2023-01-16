#include <stdio.h>

void revStr(char *start, char *end)
{
    for (char *li = start, *ri = end - 1; li < ri; ++li, --ri)
    {
        char ch = *li;
        *li = *ri;
        *ri = ch;
    }
}

int intToStr(char *str, int number)
{
    char *end = str;
    while (number > 0)
    {
        *end = number % 10 + '0';
        number /= 10;
        ++end;
    }
    *end = '\0';
    revStr(str, end);
    return (end - str) / sizeof(char);
}

void zipStr(char *str)
{
    int size = 0;
    char current_letter = str[0];
    int count = 1;

        for (int i = 1; str[i - 1] != '\0'; ++i)
        {
            if (str[i] == current_letter)
                {
                    count++;
                }
            else
                {
                    if (count > 1)
                    {
                        int n = intToStr(str + size, count);
                        size += n;
                        str[size++] = current_letter;
                    }
                    else
                    {
                        str[size++] = current_letter;
                    }
                    current_letter = str[i];
                    count = 1;
                }
        }

            if (count > 1)
            {
                int n = intToStr(str + size, count);
                size += n;
                str[size++] = current_letter;
            }
            else
            {
                str[size++] = current_letter;
            }
    str[size] = '\0';
}


int main()
{
    char str[1024];
    printf("Enter string  -> ");
    fgets(str, 1024, stdin);

    zipStr(str);

    printf("Result string -> ");
    fputs(str, stdout);
    return 0;
}
