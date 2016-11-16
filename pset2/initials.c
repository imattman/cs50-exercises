#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    string name = get_string(); 

    int print_next = 1;
    for (int i = 0, len = strlen(name); i < len; i++)
    {
        char c = name[i];
        if (c == ' ')
        {
            print_next = 1;
        }
        else if (isalpha(c) && print_next)
        {
            printf("%c", toupper(c));
            print_next = 0;
        }
    }
    printf("\n");
}