#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

void usage(string progname);
char shift_char(char c, int n);

int main(int argc, string argv[])
{
    // validate arg count and value
    if (argc != 2)
    {
        usage(argv[0]);
        return 1;
    }
    
    // exercise specifies shift must be a positive number 
    int n = atoi(argv[1]);
    if (n < 1)
    {
        usage(argv[0]);
        return 1;
    }
    
    string cleartext = get_string();
    
    // iterate over chars of cleartext, processing alpha chars with caeser shift
    for (int i = 0, len = strlen(cleartext); i < len; i++)
    {
        char c = cleartext[i];
        printf("%c", shift_char(c, n));
    }
    
    printf("\n");
}

void usage(string progname)
{
    printf("Usage: %s <N>\n", progname);
    printf("\n  Where N must be an integer greater than zero\n");
}

char shift_char(char c, int n)
{
    // no change needed if char is non-alpha or shift amount is zero
    if (!isalpha(c) || n == 0)
    {
        return c;
    }

    //
    // what goes here?
    //
    
    return c;
}
