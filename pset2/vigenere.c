#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

void usage(string progname);
int keychar_to_n(char kc);
char shift_char(char c, int n);

int main(int argc, string argv[])
{
    // validate arg count and value
    if (argc != 2)
    {
        usage(argv[0]);
        return 1;
    }

    string keyword = argv[1];
    int keylen = strlen(keyword);
    for (int i = 0; i < keylen; i++)
    {
        if (!isalpha(keyword[i]))
        {
            usage(argv[0]);
            return 1;
        }
    }
    
    // validation passed
    // collect clear text and do the actual work
    string cleartext = get_string();

    // iterate over chars of cleartext, processing alpha chars shift of keyword char
    for (int i = 0, ki = 0, len = strlen(cleartext); i < len; i++)
    {
        char c = cleartext[i];
        if (isalpha(c))
        {
            // need to keep a separate keyword 'ki' index since it conditionally
            // advances only with alphabet values in the plaintext
            char kc = keyword[ki % keylen];
            int n = keychar_to_n(kc);
            c = shift_char(c, n);
            ki++;
        }
        printf("%c", c);
    }
    
    printf("\n");
}

void usage(string progname)
{
    printf("Usage: %s KEYWORD\n", progname);
    printf("\n  Where KEYWORD must be composed of only alphabetic characters\n");
}

int keychar_to_n(char c)
{
    if (!isalpha(c))
    {
        return 0;
    }
    
    char ascii_offset = islower(c) ? 'a' : 'A';
    return c - ascii_offset;
}


char shift_char(char c, int n)
{
    // no change needed if char is non-alpha or shift amount is zero
    if (!isalpha(c) || n == 0)
    {
        return c;
    }

    // modulo 26 only works if letter is in range 0-25
    // so convert from ascii code to ordinal index
    char ascii_offset = islower(c) ? 'a' : 'A';
    int idx = c - ascii_offset;

    // apply shift, mod 26 to wrap if needed...
    int shifted_idx = (idx + n) % 26;
    
    // ...then convert back to ascii
    return shifted_idx + ascii_offset;
}
