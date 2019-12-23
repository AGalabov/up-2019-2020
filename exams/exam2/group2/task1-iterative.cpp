#include <iostream>
#include <cstring>

using namespace std;

//Assuming this function is called on letters only
int toLetterIndex(char x)
{
    if ('a' <= x && x <= 'z')
    {
        return x - 'a';
    }

    return x - 'A';
}

/*
* Putting const in front makes the value immutable
* Therfore any attempts at changing it will lead to an error
*/
void countLetters(const char *str1, const char *str2, int *letterBallance)
{
    int len = strlen(str1);
    for (int i = 0; i < len; ++i)
    {
        int str1LetterIndex = toLetterIndex(str1[i]);
        int str2LetterIndex = toLetterIndex(str2[i]);

        letterBallance[str1LetterIndex]++;
        letterBallance[str2LetterIndex]--;
    }
}

bool isZeroFilled(const int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] != 0)
        {
            return false;
        }
    }
    return true;
}

bool shuffle(const char *str1, const char *str2)
{
    //The English alphabet has 26 letters
    int letterBallance[26] = {0};

    countLetters(str1, str2, letterBallance);

    return isZeroFilled(letterBallance, 26);
}

int main()
{
    cout << shuffle("Exam", "MaXe") << '\n'  // true (1)
         << shuffle("AsDa", "AsdD") << '\n'; // false (0)

    return 0;
}