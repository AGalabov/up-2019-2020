#include <iostream>
#include <cstring>

using namespace std;

bool isInFirstTenSmallLetters(const char x)
{
    return 'a' <= x && x <= 'j';
}

bool isDigit(const char x)
{
    return '0' <= x && x <= '9';
}

char toSmallLetter(const char x)
{
    return x - '0' + 'a';
}

bool compare(const char s[], const char N[])
{
    int i = 0;
    while (s[i] != '\0' && N[i] != '\0')
    {
        if (s[i] != toSmallLetter(N[i]))
        {
            return false;
        }
        ++i;
    }

    return s[i] == N[i];
}

int main()
{
    char X[256]; // 255 symbols max and 1 for '\0'
    cin.getline(X, 256);
    char s[256], N[256];
    int smallsIndex = 0, digitsIndex = 0;
    for (int i = 0; i < strlen(X); ++i)
    {
        if (isInFirstTenSmallLetters(X[i]))
        {
            s[smallsIndex] = X[i];
            smallsIndex++;
        }
        if (isDigit(X[i]))
        {
            N[digitsIndex] = X[i];
            digitsIndex++;
        }
    }

    cout << ((compare(s, N) ? "Yes" : "No")) << endl;
}