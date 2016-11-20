#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

/*
 * revvigenere:  Reverse Vigenere for computing the complement keyword for use with a Vigenere cipher
 */

void usage(string progname);

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
    
    for (int i = 0; i < keylen; i++)
    {
        char c = keyword[i];
        if (isalpha(c))
        {
            char ascii_offset = islower(c) ? 'a' : 'A';
            int idx = c - ascii_offset;
            // char revc = ((26 - idx) % 26) + ascii_offset; // mod not needed with subtract
            char revc = (26 - idx) + ascii_offset;
            
            // printf("%c (%i) => %c\n", c, idx, revc);
            c = revc;
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
