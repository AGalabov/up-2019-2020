#include <iostream>
#include <cstring>

using namespace std;

bool isSmallLetter(const char x)
{
    return 'a' <= x && x <= 'z';
}

bool isCapitalLetter(const char x)
{
    return 'A' <= x && x <= 'Z';
}

char toSmallLetter(const char x)
{
    return x - 'A' + 'a';
}

bool compare(const char s[], const char S[])
{
    int i = 0;
    while (s[i] != '\0' && S[i] != '\0')
    {
        if (s[i] != toSmallLetter(S[i]))
        {
            return false;
        }
        ++i;
    }

    return s[i] == S[i];
}

int main()
{
    char X[256]; // 255 symbols max and 1 for '\0'
    cin.getline(X, 256);
    char s[256], S[256];
    int smallsIndex = 0, capitalIndex = 0;
    for (int i = 0; i < strlen(X); ++i)
    {
        if (isSmallLetter(X[i]))
        {
            s[smallsIndex] = X[i];
            smallsIndex++;
        }
        if (isCapitalLetter(X[i]))
        {
            S[capitalIndex] = X[i];
            capitalIndex++;
        }
    }

    cout << ((compare(s, S) ? "Yes" : "No")) << endl;
}