#include <stdio.h>
#include <cs50.h>

bool is_capital(char c);

int main(void)
{
    char c = get_char("Char: ");
    printf("char: %i\n", c);

    if (is_capital(c))
    {
        printf("capital\n");
    }
    else
    {
        printf("not capital \n");
    }

}

bool is_capital(char c)
{
    return (c >= 65 && c <= 90);  // ASCII value of c is between A and Z
}

/*
string get_cyphertext(string p, int key)
{
    int diff = 64; // difference between ASCII values and numbers of letters: B=66, B=66-64=2
    string c = p; // cyphertext
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // convert char number from ASCII to 1-26, add key and then convert back to ASCII
        // the modulo is used to wrap, so Z + 1 is 'A' and not '['
        c[i] = (p[i] - diff + key) % 26 + diff;

    }

    return c;
}
*/