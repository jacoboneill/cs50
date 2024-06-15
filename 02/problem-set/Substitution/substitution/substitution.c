#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_argc(int argc);
bool check_key_length(string key);
bool check_key_alpha(string key);
bool check_key_duplicates(string key);
string encrypt(string key, string s);

int main(int argc, string argv[])
{
    if (!check_argc(argc) || !check_key_length(argv[1]) || !check_key_alpha(argv[1]) ||
        !check_key_duplicates(argv[1]))
    {
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext:");

    printf("ciphertext:%s\n", encrypt(key, plaintext));

    return 0;
}

bool check_argc(int argc)
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    else
    {
        return true;
    }
}

bool check_key_length(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    else
    {
        return true;
    }
}

bool check_key_alpha(string key)
{
    int s_len = strlen(key);
    for (int i = 0; i < s_len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabet\n");
            return false;
        }
    }
    return true;
}

bool check_key_duplicates(string key)
{
    int s_len = strlen(key);
    char characters[s_len];

    for (int i = 0; i < s_len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (key[i] == characters[j])
            {
                printf("Key must only contain unique characters\n");
                return false;
            }
        }
        characters[i] = key[i];
    }
    return true;
}

string encrypt(string key, string s)
{
    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++)
    {
        if (isupper(s[i]))
        {
            s[i] = toupper(key[s[i] - 'A']);
        }
        else if (islower(s[i]))
        {
            s[i] = tolower(key[s[i] - 'a']);
        }
    }

    return s;
}
