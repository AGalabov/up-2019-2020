#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char c[1000];
    char str2[1000];
    cin.getline(c, 1000);

    for (int i = strlen(c) - 1; i >= 0; i--)
    {
        str2[strlen(c) - i - 1] = c[i];
    }
    str2[strlen(c)] = '\0';

    cout << "Reverse is: " << str2 << endl;

    // Using the built in strcmp function from string.h
    /*if (!strcmp(c, str2)) {
		cout << "The string is a palindrome\n";
	}*/
    bool isPalindrome = true;
    for (int i = 0; i < strlen(c); ++i)
    {
        if (c[i] != str2[i])
        {
            cout << "The string is not a palindrome\n";
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome)
    {
        cout << "The string is a palindrome\n";
    }

    return 0;
}