#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

bool is_key_valid(int argc, string argument);
int get_key(int argc, string argv[]);
string get_cyphertext(string p, int key);
bool is_letter(char c);
bool is_capital(char c);

int main(int argc, string argv[])
{
    int key = get_key(argc, argv);

    string plaintext = get_string("plaintext: ");

    string cyphertext = get_cyphertext(plaintext, key);
    printf("ciphertext: %s\n", cyphertext);
}


// check if key is a number
bool is_key_valid(int argc, string argument)
{
    for (int i = 0, n = strlen(argument); i < n; i++)
    {
        char c = argument[i];
        if (c < 48 || c > 57) // check if the ASCII value doesn't correspond to a digit 0 to 9
        {
            return false;
        }
    }
    return true;
}

// check argumets validity and returns key
int get_key(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }

    string argument = argv[1];

    if (is_key_valid(argc, argument) == false)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }

    return atoi(argument); // key
}

bool is_letter(char c)
{
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

bool is_capital(char c)
{
    return (c >= 65 && c <= 90);  // ASCII value of c is between A and Z
}

string get_cyphertext(string p, int key)
{

    int diff_upper = 64; // difference between ASCII values and numbers of letters: B=66, B=66-64=2
    int diff_lower = 96; // difference for lower-case leters: b=98, b=98-96=2
    string c = p; // ciphertext

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // convert char number from ASCII to 1-26, add key and then convert back to ASCII
        // the modulo is used to wrap, so Z + 1 is 'A' and not '['
        
        char letter = p[i];
        if (is_letter(letter) && is_capital(letter))
        {
            c[i] = (letter - diff_upper + key) % 26 + diff_upper;
        }
        else if (is_letter(letter)) // lower-case letter
        {
            c[i] = (letter - diff_lower + key) % 26 + diff_lower;
        }
        else // not a letter
        {
            c[i] = letter;
        }

    }

    return c;
}




