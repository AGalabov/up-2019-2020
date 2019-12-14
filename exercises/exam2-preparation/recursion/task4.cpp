#include <iostream>
#include <string.h>

using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

bool isALetter(char a)
{
    return (a >= 'a' && a <= 'z') ||
           (a >= 'A' && a <= 'Z');
}

void reverseString(char a[], int current)
{
    if (current > strlen(a) / 2)
        return;
    swap(a[current], a[strlen(a) - current - 1]);
    reverseString(a, current + 1);
}

void reverseSubstring(char a[], int current, int startIndex, int endIndex)
{
    if (current > startIndex + ((endIndex - startIndex) / 2))
        return;
    swap(a[current], a[startIndex + (endIndex - current)]);
    reverseSubstring(a, current + 1, startIndex, endIndex);
}

int main()
{

    char str[100];
    cin.getline(str, 100);

    bool startOfWord = false;
    int startIndex = 0;
    int endIndex = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isALetter(str[i]) && !startOfWord)
        {
            startOfWord = true;
            startIndex = i;
        }
        else if (!isALetter(str[i]) && startOfWord)
        {
            endIndex = i - 1;
            reverseSubstring(str, startIndex, startIndex, endIndex);
            startOfWord = false;
        }
    }
    if (startOfWord)
    {
        reverseSubstring(str, startIndex, startIndex, strlen(str) - 1);
    }

    cout << str << endl;

    return 0;
}